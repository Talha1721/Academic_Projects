import re
s=input()
#st=re.findall(r'[^AaEeIiOoUu][AaEeIiOoUu][AaEeIiOoUu]+$[^AaEeIiOoUu]',s)
st=re.findall(r'(?=([^AaEeIiOoUu][AaEeIiOoUu]+[^AaEeIiOoUu]))',s)
t=[]
for k in st:

    j=k[1:-1]
    if len(j)>1:
        t.append(j)
        print(j)
if not t:
    print("-1")
#rabcdeefgyYhFjkIoomnpOeorteeeeet
#escape special characters
#match a single character not present in the list below