#!/usr/bin/env python3
import os
import smtplib
import socks
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
from argparse import ArgumentParser

def load_config():
    config = {}
    with open(os.path.expanduser("~/.send_to_kindle"), "r") as f:
        for line in f.readlines():
            line = line.rstrip("\n").split("=", 1)
            config[line[0].strip(" ")] = line[1].strip(" ")
    return config

def send_book(config, file_name):
    server = smtplib.SMTP_SSL(config["server"], int(config["port"]))
    server.login(config["sender"], config["password"])

    outer = MIMEMultipart()
    outer["From"] = config["sender"]
    outer["To"] = config["target"]
    outer["Subject"] = os.path.basename(file_name)

    contype = "application/octet-stream"
    maintype, subtype = contype.split("/", 1)
    with open(file_name, 'rb') as f:
        file_msg = MIMEBase(maintype, subtype)
        file_msg.set_payload(f.read())
    encoders.encode_base64(file_msg)
    file_msg.add_header('Content-Disposition', 'attachment', filename = os.path.basename(file_name))
    outer.attach(file_msg)

    try:
        server.sendmail(config["sender"], config["target"], outer.as_string())
        print(os.path.basename(file_name), "sent")
    except:
        print("Error sending", os.path.basename(file_name))
    server.quit()

def setproxy(config):
    socks.setdefaultproxy(socks.PROXY_TYPE_SOCKS5, config["proxy"], int(config["proxy_port"]))
    socks.wrapmodule(smtplib)
    return socks

def main():
    config = load_config()
    if "proxy" in config.keys():
        socks = setproxy(config)

    parser = ArgumentParser()
    parser.add_argument("file_name")
    args = parser.parse_args()

    send_book(config, args.file_name)

if __name__ == '__main__':
    main()
