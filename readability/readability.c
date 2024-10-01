#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    float index;
    float l_index = 0;
    float s_index = 0;
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    l_index = ((float) letters / (float) words) * 100.0;

    s_index = ((float) sentences / (float) words) * 100.0;

    index = 0.0588 * l_index - 0.296 * s_index - 15.8;

    // Print the grade level

    int findex = round(index);

    if (findex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (findex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", findex);
    }
}

int count_letters(string text)
{
    int lcount = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] != ' ' && text[i] != '.' && text[i] != '!' && text[i] != '?' && text[i] != ',' && text[i] != '\'')
        {
            lcount += 1;
        }
    }
    // Return the number of letters in text
    return lcount;
}

int count_words(string text)
{
    int wcount = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            wcount += 1;
        }
    }
    // Return the number of words in text
    return wcount;
}

int count_sentences(string text)
{
    int scount = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            scount += 1;
        }
    }
    // Return the number of sentences in text
    return scount;
}
