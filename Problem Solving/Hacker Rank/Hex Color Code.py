import re
l=[]
n=int(input())
for i in range(n):
    l.append(input().strip())
pattern=r'(?<!^)(#(?:[\da-fA-F]{3}){1,2})'
#pattern=r'#(?:([\da-fA-F]{3}){1,2})'
for j in range(n):
    pt=re.findall(pattern,l[j])
    if(pt):
        for k in pt:
            print(k)

"""
BED
dF8
aef
9f9
fff
Cab
ABC
fff
"""