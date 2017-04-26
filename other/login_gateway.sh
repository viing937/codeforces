#!/usr/bin/bash

VIEWSTATE=`curl wg.suda.edu.cn 2>/dev/null | grep __VIEWSTATE | sed 's/\(.*\)value="\(.*\)"\(.*\)/\2/g'`
EVENTVALIDATION=`curl wg.suda.edu.cn 2>/dev/null | grep __EVENTVALIDATION | sed 's/\(.*\)value="\(.*\)"\(.*\)/\2/g'`
user=$1
passwd=$2
tm='RadioButton8' # 10 hours

curl wg.suda.edu.cn --data-urlencode "__VIEWSTATE=$VIEWSTATE" \
                    --data-urlencode "__EVENTVALIDATION=$EVENTVALIDATION" \
                    --data "TextBox1=$user&TextBox2=$passwd&nw=RadioButton1&tm=$tm&Button1=登陆网关" 2>/dev/null \
                    | grep $user \
                    | tr -d ' \t' \
                    | sed 's/<[^>]*>//g'
