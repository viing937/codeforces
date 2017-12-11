# coding: utf-8
from bs4 import BeautifulSoup
import requests
import time
import random

urlsFile = 'urls.txt'
visitedUrlsFile = 'visited.txt'
dataDir = 'data/'
domain = 'http://you.ctrip.com'

def get_relative_url(urls, bs):
    for link in bs.find_all(attrs = {'class': 'asklink'}):
        url = link.get('href')
        urls.add(url)
    with open(urlsFile, 'w') as f:
        f.write('\n'.join(urls))

def get_info(bs, url):
    try:
        title = bs.find(attrs = {'class': 'ask_title'}).text.strip()
        question = bs.find(attrs = {'class': 'ask_text'}).text.strip()
        answer = map(lambda x: x.text.strip(), bs.find_all(attrs = {'class': 'answer_text'}))
        with open(dataDir + url.replace('/', '') + '.txt', 'w') as f:
            f.write(title + '\n')
            f.write(question + '\n')
            f.write('\n'.join(answer))
        with open(visitedUrlsFile, 'a') as f:
            f.write(url+'\n')
        print(title)
    except Exception as err:
        print(err)

def get_url(urls):
    url = '/asks/p' + str(random.randint(1, 50))
    r = requests.get(domain+url, headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:38.0) Gecko/20100101 Firefox/38.0'})
    bs = BeautifulSoup(r.text, 'html.parser')
    asklist = bs.find(attrs = {'class': 'asklist'})
    for ask in asklist.children:
        try:
            urls.add(ask.get('href'))
        except Exception as err:
            pass
    with open(urlsFile, 'w') as f:
        f.write('\n'.join(urls))

def load_urls():
    with open(urlsFile, 'r') as f:
        return set([url for url in f.read().split('\n') if url != ''])

def load_visited():
    with open(visitedUrlsFile, 'r') as f:
        return set([url for url in f.read().split('\n') if url != ''])

def main():
    urls = load_urls()
    get_url(urls)
    visited = load_visited()
    while len(urls) > 0:
        url = urls.pop()
        while len(urls) > 0 and url in visited:
            url = urls.pop()
        if len(urls) == 0:
            get_url(urls)
        visited.add(url)
        r = requests.get(domain+url, headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:38.0) Gecko/20100101 Firefox/38.0'})
        bs = BeautifulSoup(r.text, 'html.parser')
        get_info(bs, url)
        get_relative_url(urls, bs)
        time.sleep(5)

if __name__ == '__main__':
    main()
