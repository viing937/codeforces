#!/usr/bin/env python3
import os
import smtplib
import socks
import base64
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
from argparse import ArgumentParser

SERVER = 'smtp.gmail.com'
PORT = 465
SENDER = 'viing937@gmail.com'
PASSWORD = '<censored>'
TARGET = 'viing937@kindle.com'
PROXY = '127.0.0.1'
PROXY_PORT = 1080

def get_attachment(file_path):
    contype = "application/octet-stream"
    maintype, subtype = contype.split("/", 1)
    with open(file_path, "rb") as f:
        attachment = MIMEBase(maintype, subtype)
        attachment.set_payload(f.read())
    encoders.encode_base64(attachment)
    file_name = os.path.splitext(os.path.basename(file_path))
    attachment.add_header("Content-Disposition", "attachment", filename = base64.b64encode(file_name[0].encode("utf-8")).decode("utf-8")+file_name[1])
    return attachment

def send_book(file_path):
    outer = MIMEMultipart()
    outer["From"] = SENDER
    outer["To"] = TARGET
    outer["Subject"] = os.path.basename(file_path)

    outer.attach(get_attachment(file_path))

    try:
        server = smtplib.SMTP_SSL(SERVER, PORT)
        server.login(SENDER, PASSWORD)
        server.sendmail(SENDER, TARGET, outer.as_string())
        print("Send", os.path.basename(file_path), "successfully")
    except:
        print("Error sending", os.path.basename(file_path))
    server.quit()

def set_proxy():
    socks.setdefaultproxy(socks.PROXY_TYPE_SOCKS5, PROXY, PROXY_PORT)
    socks.wrapmodule(smtplib)
    return socks

def main():
    socks = set_proxy()
    try:
        socks = set_proxy()
        print('proxy:', PROXY + ':' + str(PROXY_PORT))
    except:
        print('proxy: None')

    parser = ArgumentParser()
    parser.add_argument("file_path")
    args = parser.parse_args()

    send_book(args.file_path)

if __name__ == '__main__':
    main()
