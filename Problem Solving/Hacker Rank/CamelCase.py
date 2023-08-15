def camelcase(s):
    l='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    ct=1
    for i in range(len(s)):
        if s[i] in l:
            ct+=1
    print(ct)

if __name__ == '__main__':
   camelcase(input())
