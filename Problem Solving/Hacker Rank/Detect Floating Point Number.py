import re
k=[]
for i in range(int(input())):
    k.append(input())
for j in k:
    print(bool(re.match(r'^[-+]?[0-9]*\.[0-9]+$', j)))

