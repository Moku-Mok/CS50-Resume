// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
//Value to check if a dictionary is loaded
bool dicLoaded = false;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashNum = hash(word);
    node* ptr = table[hashNum];

    while (ptr != NULL)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }

        ptr = ptr->next;

    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    //buffer that can hold the longest word specified by LENGTH + one whitespace.
    char buffer[LENGTH + 1];

    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    while ( fscanf(source, "%s", buffer) != EOF )
        {
            //Reserve space for a new_word node entry.
            node *new_word = malloc(sizeof(node));

            if (new_word == NULL)
            {
                unload();
                return false;
            }

            else
            {
                //Declare new_word's word to be what got read into the buffer.
                strcpy(new_word->word, buffer);

                //Run hash on the word in buffer.
                int hashNum = hash(buffer);


                //Make new_word point to whatever is the first thing in the table
                new_word->next = table[hashNum];
                //Add new_word to the table.
                table[hashNum] = new_word;

            }
        }

    // Read each word in the file

        // Add each word to the hash table

    // Close the dictionary file
    fclose(source);
    dicLoaded = true;

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int wordCount = 0;

    if (dicLoaded == false)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        node* ptr = table[i];
        while (ptr != NULL)
        {
            wordCount++;
            ptr = ptr->next;
        }
    }

    return wordCount;

    //   WORKS FOR NOW!
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    if (dicLoaded == false)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        node* ptr = table[i];

        while (ptr != NULL)
        {
            node* next = ptr->next;
            free(ptr);
            ptr =next;
        }
    }

    return true;
}
