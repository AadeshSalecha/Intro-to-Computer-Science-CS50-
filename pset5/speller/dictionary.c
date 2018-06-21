// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"


// Default dictionary
#define DICTIONARY "dictionaries/large"

int numWords = 0, collisions, maxi = 0;
int chainLength[BUCKETS] = {0};
char duplicateCheck[50];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    strcpy(duplicateCheck, word);

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        duplicateCheck[i] = tolower(duplicateCheck[i]);
    }

    // Hash it
    int index = hash(duplicateCheck);

    // Go through it and check
    return search(tabel[index], duplicateCheck);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for (int i = 0; i < BUCKETS; i++)
    {
        tabel[i] = NULL;
    }

    // Open File
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        printf("Could not open dictionary for reading.\n");
        return false;
    }

    // Read word
    char word[50];
    while (fscanf(inptr, "%s\n", word) != EOF)
    {
        numWords++;

        // Hash it
        int index = hash(word);

        /*
        // Attach to Linked list
        if(tabel[index] != NULL)
        {
            collisions++;
            chainLength[index]++;
            if(chainLength[index] > maxi)
                maxi = chainLength[index];
        }
        */
        insert(index, word);
    }
    /*
    int sum = 0, zero= 0;
    for (int i = 0; i < BUCKETS; i++)
    {
        if(chainLength[i] != 0)
            sum += chainLength[i];
        else
            zero++;
    }

    printf("Collisions: %i\nMaxi: %i\n Avg: %f\nZero %i\n", collisions, maxi, (float)sum / (BUCKETS-zero), zero);
    for (int i = 1000; i < 3000; i++)
    {
        printf("%i %i\n", i, chainLength[i]);
    }
    */
    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return numWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    struct node *next;
    struct node *current;
    for (int i = 0; i < BUCKETS; i++)
    {
        current = tabel[i];
        while (current != NULL)
        {
            next = current->nextptr;
            free(current->data);
            free(current);
            current = next;
        }
    }
    return true;
}

// Return hash value of word
int hash(string word)
{
    /*unsigned int h = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        h = (h << 2) ^ word[i];
    }*/
    int h = 0;
    for (int i = strlen(word); i >= 0; i--)
    {
        h = (h * XforHash + word[i]) % BUCKETS;
    }
    return h % BUCKETS;
}

bool search(struct node *root, string word)
{
    struct node *current = root;
    while (current != NULL)
    {
        if (strcmp(current->data, word) == 0)
        {
            return true;
        }
        current = current->nextptr;
    }
    return false;
}

void insert(int index, string word)
{
    struct node *tmp = malloc(sizeof(struct node) * 1);
    char *duplicate = malloc(sizeof(char) * (strlen(word) + 1));

    strcpy(duplicate, word);
    tmp->data = duplicate;
    tmp->nextptr = tabel[index];
    tabel[index] = tmp;
}
