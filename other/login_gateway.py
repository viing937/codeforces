# coding: utf-8
import requests
from bs4 import BeautifulSoup

user = ''
passwd = ''
time = 'RadioButton8' # 10 hours
action = '登陆网关'
# action = '退出网关'


# get web 
r = requests.get('http://wg.suda.edu.cn')

# __VIEWSTATE和__EVENTVALIDATION
soup = BeautifulSoup(r.content)
viewstate = soup.find_all('input')[0]['value']
eventvalidation = soup.find_all('input')[13]['value']

# params 
params = {}
params['__VIEWSTATE'] = viewstate
params['TextBox1'] = user 
params['TextBox2'] = passwd
params['nw'] = 'RadioButton1'
params['tm'] = time
if action == '登陆网关':
    params['Button1'] = action
elif action == '退出网关':
    params['Button4'] = action
params['__EVENTVALIDATION'] = eventvalidation

# login 
r = requests.post('http://wg.suda.edu.cn', data=params)

# reponse 
soup = BeautifulSoup(r.content)
print soup.find_all('li')[3].get_text().strip()
