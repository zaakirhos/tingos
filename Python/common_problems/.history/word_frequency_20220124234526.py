import re
from collections import defaultdict

# 1. pure algorithm
def count_word_frequency1(text):
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


# 2. with defaultdict
def count_word_frequency2(text):
    words = text.split()
    wordList = [(word, index) for index, word in enumerate(words)]
    # print(wordList)
    word_count = defaultdict(list)
    # print(word_count)
    for word, index in wordList:
        word_count[word].append(index)

    print(word_count.items()[0])

    # sorted(d.items())
    # [('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]


words = """People demand freedom of speech as a compensation for the 
freedom of thought which they seldom use."""

# make the words lowercase and remove the punctuation
words = re.sub(r"[^\w\s]", "", words.lower())


def main():
    frequency = count_word_frequency2(words)
    print(frequency)


if __name__ == "__main__":
    main()
