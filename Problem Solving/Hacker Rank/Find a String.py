def count_substring(word, sub):
    count = 0
    pos = 0
    while (True):
        pos = word.find(sub, pos)
        if pos > -1:
            count += 1
            pos += 1
        else:
            break
    return count


if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()

    count = count_substring(string, sub_string)
    print(count)