""""
import re
n = int(input())
for _ in range(n):
    x, y = input().split(' ')
    m = re.match(r'<[A-Za-z](\w|-|\.|_)+@[A-Za-z]+\.[A-Za-z]{1,3}>', y)
    if m:
        print(x,y)
"""
import re
l=[]
n=int(input())
for i in range(n):
    l.append(input())
pattern=r'^<[A-Za-z](\w|-|\.|_)+@[A-Za-z]+\.[A-Za-z]{1,3}>$'
for j in range(n):
    x, y=l[j].split()
    if(re.match(pattern,y)):
        print(x, y)
