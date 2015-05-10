s = input()
if s[:3] == "ftp":
    pre = "ftp://"
    s = s[3:]
elif s[:4] == "http":
    pre = "http://"
    s = s[4:]
index = s[1:].index("ru")+1
if index == len(s)-2:
    s = pre+s[:index]+"."+s[index:]
else:
    s = pre+s[:index]+"."+s[index:index+2]+"/"+s[index+2:]
print(s)
