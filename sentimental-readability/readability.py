from cs50 import get_string


def count_letters(inputText):

    lcount = 0

    for x in inputText:
        if x != ' ' and x != '.' and x != '!' and x != '?' and x != ',' and x != "'":
            lcount += 1

    return lcount
##


def count_words(inputText):

    wcount = 1

    for x in inputText:
        if x == ' ':
            wcount += 1

    return wcount
##


def count_sentences(inputText):

    scount = 0

    for x in inputText:
        if x == '.' or x == '!' or x == '?':
            scount += 1

    return scount
##


def main():

    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    print(letters)
    print(words)
    print(sentences)
##

    l_index = (letters / words) * 100
    s_index = (sentences / words) * 100

    index = round(0.0588 * l_index - 0.296 * s_index - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


main()
