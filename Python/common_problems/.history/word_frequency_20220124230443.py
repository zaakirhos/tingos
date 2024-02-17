# 1. pure algorithm


def count_word_frequency(text):
    """
    Count the frequency of each word in a text.
    """
    words = text.split()
    word_count = {}
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    return word_count


words = """Marry, and you will regret it; don’t marry, you will also 
regret it; marry or don’t marry, you will regret it either way. 
Laugh at the world’s foolishness, you will regret it; weep over it, 
you will regret that too; laugh at the world’s foolishness or 
weep over it, you will regret both. Believe a woman, you will regret 
it; believe her not, you will also regret it… Hang yourself, you will regret it; do not hang yourself, and you will regret that too; hang yourself or don’t hang yourself, you’ll regret it either way; whether you hang yourself or do not hang yourself, you will regret both. This, gentlemen, is the essence of all philosophy.
"""


def main():
    frequency = count_word_frequency("The ")
    print(frequency)


if __name__ == "__main__":
    main()
