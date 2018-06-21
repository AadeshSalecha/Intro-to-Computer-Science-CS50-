// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <cs50.h>
#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define BUCKETS 200003
#define XforHash 31

struct node
{
    struct node* nextptr;
    string data;
};

struct node* tabel[BUCKETS];

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

int hash(string word);
bool search(struct node* root, string word);
void insert(int index, string word);

#endif // DICTIONARY_H
