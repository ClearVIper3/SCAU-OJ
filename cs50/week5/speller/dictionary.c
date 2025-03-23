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
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index=hash(word);
    node *ptr=table[index];
    while(ptr!=NULL)
    {
        if(strcasecmp(ptr->word,word)==0)
        {
            return true;
        }
        ptr=ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hash=0;
    for(int i=0;word[i]!='\0';i++)
    {
        hash = (hash*31+toupper(word[i]))%N;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *input=fopen(dictionary,"r");
    if(input==NULL)
    {
        return false;
    }

    char a[LENGTH+1];
    while((fscanf(input,"%s",a))!=EOF)
    {
        if (strlen(a) > LENGTH)
        {
            fclose(input);
            return false;
        }
        node *nhash=malloc(sizeof(node));
        strcpy(nhash->word,a);
        unsigned int index=hash(a);
        nhash->next=table[index];
        table[index]=nhash;

    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int size=0;
    for(int i=0;i<N;i++)
    {
        node *ptr=table[i];
        while(ptr!=NULL)
        {
            size++;
            ptr=ptr->next;
        }
    }
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i=0;i<N;i++)
    {
        node* ptr=table[i];
        while(ptr!=NULL)
        {
            node *f=ptr;
            ptr=ptr->next;
            free(f);
        }
    }
    return true;
}
