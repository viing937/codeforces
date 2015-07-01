# coding: utf-8
from bs4 import BeautifulSoup
import requests
import time
import re

def get_url(urls, bs):
    for link in bs.find_all(name='a'):
        if len(urls) > 100:
            break
        url = link.get('href')
        if re.match(r'^/shop/[0-9]*$', str(url)):
            urls.add(url)

def get_info(bs):
    try:
        info = bs.find(attrs = {'class': 'basic-info'})
        name = info.find(attrs = {'class': 'shop-name'}).text.split('\n')[1]
        address = ''.join([s.strip(' ')for s in info.find(attrs = {'class': 'expand-info address'}).text.split('\n')])
        print(name, address)
    except:
        pass

def main():
    domain = 'http://www.dianping.com'
    urls = set(['/shop/1721578'])
    while len(urls) > 0:
        r = requests.get(domain+urls.pop(), headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:38.0) Gecko/20100101 Firefox/38.0'})
        bs = BeautifulSoup(r.text)
        get_url(urls, bs)
        get_info(bs)
        time.sleep(4)

if __name__ == '__main__':
    main()
