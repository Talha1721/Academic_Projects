l=[]
n=int(input())
for i in range(n):
    r= []
    a, b = map(str, input().split())
    r.append(a)
    r.append(b)
    l.append(r)
for j in range(n):
    try:
        print(int(l[j][0])//int(l[j][1]))
    except BaseException as e:
        print("Error Code:",e)

