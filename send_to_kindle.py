#!/usr/bin/env python3
import os
import smtplib
import socks
import base64
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

def send_book(config, file_path):
    outer = MIMEMultipart()
    outer["From"] = config["sender"]
    outer["To"] = config["target"]
    outer["Subject"] = os.path.basename(file_path)

    outer.attach(get_attachment(file_path))

    try:
        server = smtplib.SMTP_SSL(config["server"], int(config["port"]))
        server.login(config["sender"], config["password"])
        server.sendmail(config["sender"], config["target"], outer.as_string())
        print("Send", os.path.basename(file_path), "successfully")
    except:
        print("Error sending", os.path.basename(file_path))
    server.quit()

def set_proxy(config):
    socks.setdefaultproxy(socks.PROXY_TYPE_SOCKS5, config["proxy"], int(config["proxy_port"]))
    socks.wrapmodule(smtplib)
    return socks

def main():
    config = load_config()
    if "proxy" in config.keys():
        socks = set_proxy(config)

    parser = ArgumentParser()
    parser.add_argument("file_path")
    args = parser.parse_args()

    send_book(config, args.file_path)

if __name__ == '__main__':
    main()
