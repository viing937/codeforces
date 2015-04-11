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
        body = bs.find(id='artibody').find_all('p')
        title = bs.find(id='artibodyTitle').text
        with open('tmp/'+title.strip(),'w') as f:
            for ln in body:
                f.write(ln.text+'\n')
    except Exception:
        print(url)
