import random

with open('text.txt') as f:
    words = [word for word in f.read().replace('\n', ' ').replace('.', ' . ')
                                      .replace(',', ' , ').replace('!', ' ! ')
                                      .replace('?', ' ? ').replace('"', ' " ')
                                      .split(' ') if word != '']
wt = {}
for i in range(2, len(words)):
    if words[i-2] not in wt:
        wt[words[i-2]] = {}
    if words[i-1] not in wt[words[i-2]]:
        wt[words[i-2]][words[i-1]] = []
    wt[words[i-2]][words[i-1]].append(words[i])

start = input('Enter the start word: ')
text = [start, random.choice(list(wt[start].keys()))]
while len(text) < 1000:
    try:
        text.append(random.choice(wt[text[-2]][text[-1]]))
    except:
        if len(text) > 2:
            text.pop()
        else:
            text = [start, random.choice(list(wt[start].keys()))]

print(' '.join(text))
