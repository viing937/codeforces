# send_to_kindle

Send books to kindle via email.

## config

Create a config file ~/.send_to_kindle.
Example:

    server = smtp.qq.com
    port = 465
    sender = email_address
    password = login_password
    target = kindle@kindle.com
    proxy = 127.0.0.1
    proxy_port = 1080

## notice

In order to use gmail to send emails, enable ["Access for less secure apps"](https://www.google.com/settings/security/lesssecureapps), this allows you to use the google smtp for clients other than the official ones.
