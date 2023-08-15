def merge_the_tools(s, n):
    l = []
    for i in range(0, len(s), n):
        l.append(s[i:i + n])
    for x in l:
        u = list(x)
        fx = []
        for i in range(len(x)):
            if u[i] not in fx:
                fx.append(u[i])
        fu = "".join(fx)
        print(fu)


if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)

