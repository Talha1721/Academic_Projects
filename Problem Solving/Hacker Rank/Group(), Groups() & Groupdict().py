import re
str=input()
g=re.search(r'(\w)\1+',str )

if g :
    print(g.group(1))
else:
    print("-1")

