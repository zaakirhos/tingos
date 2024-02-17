def add2(a, b):
    return a+b

def find_it(L, word):
    c = 0
    for l in word:
        if l == L:
            c+=1
    return c
def find_rec(L, word, index):
    if index == len(word):
        return 0
    else:
        inde
    return find_rec(L, word, index)

# print(add2(1, 2))
if __name__ == '__main__':
    print(find_rec("r", "swarthmore", 0))