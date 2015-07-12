# coding: utf-8
from bs4 import BeautifulSoup
import requests
import time
import re

def get_url(urls, bs):
    for link in bs.find_all(name='a'):
        url = link.get('href')
        match = re.search(r'^/shop/[0-9]*$', str(url))
        if match:
            urls.add(match.group())
            with open('urls', 'w') as f:
                for url in urls:
                    f.write(url+"\n")

def get_info(bs, url):
    try:
        info = bs.find(attrs = {'class': 'basic-info'})
        name = info.find(attrs = {'class': 'shop-name'}).text.split('\n')[1]
        address = ''.join([s.strip(' ')for s in info.find(attrs = {'class': 'expand-info address'}).text.split('\n')])
        with open('record', 'a') as f:
            f.write(name+' '+address+'\n')
        with open('visited', 'a') as f:
            f.write(url+'\n')
        print(name, address)
    except:
        pass

def load_urls():
    with open('urls', 'r') as f:
        return set([url for url in f.read().split('\n') if url != ''])

def load_visited():
    with open('visited', 'r') as f:
        return set([url for url in f.read().split('\n') if url != ''])

def main():
    domain = 'http://www.dianping.com'
    urls = load_urls()
    visited = load_visited()
    while len(urls) > 0:
        url = urls.pop()
        while url in visited:
            url = urls.pop()
        visited.add(url)
        r = requests.get(domain+url, headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:38.0) Gecko/20100101 Firefox/38.0'})
        bs = BeautifulSoup(r.text)
        get_url(urls, bs)
        get_info(bs, url)
        time.sleep(3)

if __name__ == '__main__':
    main()
