# coding: utf-8
n, m = [int(i) for i in input().split()]
w = [0]+[int(i) for i in input().split()]
b = [int(i) for i in input().split()]
books = []
for book in b:
    if book not in books:
        books.append(book)
books.reverse()
ans = 0
for book in b:
    index = books.index(book)
    ans += sum([w[i] for i in books[index+1:]])
    del(books[index])
    books.append(book)
print(ans)
