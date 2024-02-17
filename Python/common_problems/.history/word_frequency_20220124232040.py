import re

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


words = """"""

# make the words lowercase and remove the punctuation
words = re.sub(r"[^\w\s]", "", words.lower())


def main():
    frequency = count_word_frequency(words)
    print(frequency)


if __name__ == "__main__":
    main()
