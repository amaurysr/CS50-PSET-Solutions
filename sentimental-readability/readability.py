# TODO

def main():
    passage = str(input("Enter your sentence: "))

    sentences = count_sentences(passage)
    letters = count_letters(passage)
    words = count_words(passage)

    s = float((sentences/words) * 100)
    l = float((letters/words) * 100)

    index = round((0.0588 * l) - (0.296 * s) - 15.8)


    if index <= 0:
        print("Before Grade 1.")
    elif index >= 16:
        print("Grade 16+")
    elif index < 16:
        print("Grade "+str(index))


def count_sentences(sentence):
    sentences = 0
    enders = {".", "?", "!"}
    for i in sentence:
        for j in enders:
            if i == j:
                sentences += 1
    return sentences

def count_letters(sentence):
    letters = 0
    enders = {".", "?", "!", " ", "/", ",", ";", ":","'"}
    for i in sentence:
        letters += 1
        for j in enders:
            if i == j:
                letters -= 1
    return letters

def count_words(sentence):
    words = 0
    length = 0
    enders = {".", "?", "!"," ", "/", ",", ";", ":"}
    for i in sentence:
        length += 1
        for j in enders:
            if i == j:
                words += 1
                for k in enders:
                    if length < len(sentence):
                        if sentence[length] == k:
                            words -= 1
    return words


if __name__ == "__main__":
    main()
