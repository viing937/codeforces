# coding: utf-8
from bs4 import BeautifulSoup
import requests
import re
r = requests.get('http://www.sina.com.cn/')
text = r.content.decode('gbk','ignore')
bs = BeautifulSoup(text)
urls = []
for link in bs.find_all('a'):
    url = link.get('href')
    if re.match(r'.*sina.*[0-9\-]+/[0-9]+\.shtml',str(url)):
        urls.append(url)

for url in urls:
    try:
        r = requests.get(url)
        text = r.content.decode('gbk','ignore')
        bs = BeautifulSoup(text)
        title = bs.find_all('h1')[-1].contents[-1]
        print(title)
    except Exception:
        print(url)
