// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
int total_words = 0;
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word);
    char tmp_word[n + 1];
    strcpy(tmp_word, word);
    
    for (int i = 0; tmp_word[i]; i++)
    {
        tmp_word[i] = tolower(tmp_word[i]);
    }
    
    int index = hash(tmp_word);
    node *cursor = table[index];
    
    while (cursor != NULL)
    {

        if (strcasecmp(tmp_word, cursor->word) == 0)
        {
            return true;
        }
    
        cursor = cursor->next;
    }
    
    return false;
}

// Hashes word to a number
//djb2 algorithm from cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;
    
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    //Read string from file one at a time
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        //create a new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        strcpy(new_node->word, word);
        new_node->next = NULL;

        //Hash word to optain a hash value
        int index = hash(word);


        if (table[index] == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }

        total_words++;
    }
    
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return total_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp = cursor;
        
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        
    }
    return true;
}
