#!/usr/bin/env python3
import os
import smtplib

def load():
    config = {}
    with open(os.environ["HOME"]+"/.send_to_kindle", "r") as f:
        for line in f.readlines():
            line = line.rstrip("\n").split("=")
            config[line[0].strip(" ")] = line[1].strip(" ")
    return config

def send(config):
    server = smtplib.SMTP_SSL(config["server"], int(config["port"]))
    server.login(config["sender"], config["password"])
    body = '\r\n'.join(["To: %s" % config["target"],
                        "From: %s" % config["sender"],
                        "Subject: TEST"])
    try:
        server.sendmail(config["sender"], config["target"], body)
        print("Email sent.")
    except:
        print("Error sending mail.")
    server.quit()

def main():
    config = load()
    send(config)

if __name__ == '__main__':
    main()
