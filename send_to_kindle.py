#!/usr/bin/env python3
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
import os
import smtplib
import socks

def load():
    config = {}
    with open(os.path.expanduser("~/.send_to_kindle"), "r") as f:
        for line in f.readlines():
            line = line.rstrip("\n").split("=", 1)
            config[line[0].strip(" ")] = line[1].strip(" ")
    return config

def send(config, file_name):
    server = smtplib.SMTP_SSL(config["server"], int(config["port"]))
    server.login(config["sender"], config["password"])

    body = MIMEMultipart()
    body["From"] = config["sender"]
    body["To"] = config["target"]
    body["Subject"] = os.path.basename(file_name)

    contype = "application/octet-stream"
    maintype, subtype = contype.split("/", 1)
    with open(file_name, 'rb') as f:
        file_msg = MIMEBase(maintype, subtype)
        file_msg.set_payload(f.read())
    encoders.encode_base64(file_msg)
    file_msg.add_header('Content-Disposition', 'attachment', filename = os.path.basename(file_name))
    body.attach(file_msg)

    try:
        server.sendmail(config["sender"], config["target"], body.as_string())
        print("File sent.")
    except:
        print("Error sending File.")
    server.quit()

def setproxy(config):
    socks.setdefaultproxy(socks.PROXY_TYPE_SOCKS5, config["proxy"], int(config["proxy_port"]))
    socks.wrapmodule(smtplib)
    return socks

def main():
    config = load()
    if "proxy" in config.keys():
        socks = setproxy(config)
    send(config, "README.md")

if __name__ == '__main__':
    main()
