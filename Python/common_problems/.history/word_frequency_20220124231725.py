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


words = """
"""


def main():
    frequency = count_word_frequency(words.lower())
    print(frequency)


if __name__ == "__main__":
    main()
