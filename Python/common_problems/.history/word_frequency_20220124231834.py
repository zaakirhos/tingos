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


words = """What is a poet? An unhappy person who conceals profound anguish 
in his heart but whose lips are so formed that as sighs and cries pass 
over them they sound like beautiful music."""


    return re.sub(r'[^\w\s]', '', text)

def main():
    frequency = count_word_frequency(words.lower())
    print(frequency)


if __name__ == "__main__":
    main()
