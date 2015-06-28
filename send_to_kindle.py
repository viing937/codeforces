#!/usr/bin/env python3
import os
import smtplib

config = {}
with open(os.environ["HOME"]+"/.send_to_kindle", "r") as f:
    for line in f.readlines():
        line = line.rstrip("\n").split("=")
        config[line[0].strip(" ")] = line[1].strip(" ")

print(config)

