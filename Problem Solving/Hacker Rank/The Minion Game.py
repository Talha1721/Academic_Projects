
def minion_game(s):
    vowels = 'AEIOU'

    kevsc = 0
    stusc = 0
    for i in range(len(s)):
        if s[i] in vowels:
            kevsc += (len(s) - i)
        else:
            stusc += (len(s) - i)

    if kevsc > stusc:
        print("Kevin",kevsc)
    elif kevsc < stusc:
        print("Stuart",stusc)
    else:
        print("Draw")

if __name__ == '__main__':
    s=input()
    minion_game(s)


"""

def overlapped_substr(word,sub):
    count=0
    pos=0
    while (True):
        pos=word.find(sub,pos)
        if pos>-1:
            count+=1
            pos+=1
        else:
            break
    return count

def minion_game(s):
    v=['A','E','I','O','U']
    lkv=[]
    lsc=[]
    for st in list(s):
        anc=s.find(st)
        if st in v:
            for i in range(anc+1,len(s)+1):
                x=s[anc:i]
                if x not in lkv:
                    lkv.append(x)
        else:
            for j in range(anc+1,len(s)+1):
                y = s[anc:j]
                if y not in lsc:
                    lsc.append(y)

    count_lkv=0
    count_lsc=0
    for m in lkv:
        temp = overlapped_substr(s,m)
        count_lkv= count_lkv+temp
    for n in lsc:
        temp = overlapped_substr(s,n)
        count_lsc= count_lsc+temp
    if count_lkv>count_lsc:
        print("Kevin",count_lkv)
    elif count_lkv<count_lsc:
        print("Stuart",count_lsc)
    else:
        print("Draw")



if __name__ == '__main__':
    word=input()
    minion_game(word)
"""