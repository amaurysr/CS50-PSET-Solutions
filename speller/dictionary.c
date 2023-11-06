// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100;

//Tracks number of words in the dictionary
int numofwords = 0;

// Hash table
node *table[N] = {};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashval = hash(word);
    if(table[hashval] != NULL)
    {
        while(table[hashval] != NULL)
        {
            if(strcasecmp(word, table[hashval]->word)==0)
            {
                return true;
                break;
            }
            table[hashval] = table[hashval]->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int x = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        x += tolower(word[i]) % 10;
    }
    return x % 10;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char *word = malloc(sizeof(char));
    while(fscanf(file, "%s", word) != EOF)
    {
        //fscanf(file, "%s", word);
        node *n = malloc(sizeof(node));
        node *temp = malloc(sizeof(node));
        node *temp2 = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return false;
        }
        if (temp == NULL)
        {
            free(temp);
        }
        strcpy(n->word, word);
        if (numofwords == 0)
        {
            n->next = NULL;
            temp = n;
        }
        else
        {
            n->next = temp;
            temp = n;
        }
        numofwords++;
        int hashVal = hash(word);
        if(table[hashVal] == NULL)
        {
            table[hashVal] = n;
            table[hashVal]->next = NULL;
            temp2 = table[hashVal];
        }
        else
        {
            table[hashVal] = n;
            table[hashVal]->next = temp2;
            temp2 = table[hashVal];
        }
    }
    free(word);
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if(numofwords == 0)
    {
        return 0;
    }
    else
    {
        return numofwords;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int counter = 0;
    for(int i = 0; i <= N; i++)
    {
        if(table[i] != NULL)
        {
            node *cursor = malloc(sizeof(node));
            node *temp = malloc(sizeof(node));
            int count = 0;
            while(temp != NULL)
            {
                if (count == 0)
                {
                    cursor = table[i];
                    temp = cursor;
                    cursor = table[i]->next;
                    free(temp);
                    count++;
                }
                else
                {
                    temp = cursor;
                    cursor = table[i]->next;
                    free(temp);
                    count++;
                }
            }
            free(cursor);
            free(temp);
        }
        counter ++;
    }
    if(counter == N + 1)
    {
        return true;
    }
    return false;
}
