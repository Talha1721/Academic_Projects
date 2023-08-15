import re
l=[]
n=int(input())
for i in range(n):
    l.append(input())
pattern=r'^[789][0-9]{9}$'
for j in range(n):
    if(re.match(pattern,l[j])):
        print("YES")
    else:
        print("NO")