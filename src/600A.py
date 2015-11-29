import re
s = re.split(',|;', input())
a = []
b = []
for item in s:
    if item.isdigit() and (item[0]!='0' or len(item)==1):
        a.append(item)
    else:
        b.append(item)
if a:
    print("\"", ",".join(a), "\"", sep="")
else:
    print("-")
if b:
    print("\"", ",".join(b), "\"", sep="")
else:
    print("-")
