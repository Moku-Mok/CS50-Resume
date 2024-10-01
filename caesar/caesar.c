#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

string cipher(string s, int key);
bool is_only_digit(string x);

int main(int argc, string argv[])
{
    if (argc != 2 || is_only_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    //Take input
    string plaintext = get_string("plaintext:  ");
    string ciphertext = cipher(plaintext, key);



}

string cipher(string s, int key)
{
    int k = key;

    printf("ciphertext: ");

    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]) && !isdigit(s[i]) && !ispunct(s[i]) && !isspace(s[i]))
        {

            if (isupper(s[i]))
            {
                printf("%c", (((s[i] + k) - 65) % 26) + 65);
            }
            else if (islower(s[i]))
            {
                printf("%c", (((s[i] + k) - 97) % 26) + 97);
            }

        }

        else
        {
                printf("%c", s[i]);
        }


    }
    printf("\n");
    return s;
}

bool is_only_digit(string x)
{
    for (int i = 0, len = strlen(x); i < len; i++)
        if (!isdigit(x[i]))
        {
            return 1;
        }
   return 0;
}
//function that ciphers the input


