/*
 * speller.c
 *
 * Implements a speller's functionality (single-file version).
 *
 * Compile:
 *   gcc -std=c11 -Wall -Wextra -o speller speller.c
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <stdio.h>

/* ----- speller.h contents ----- */

/* Maximum length for a word (e.g., pneumonoultramicroscopicsilicovolcanoconiosis) */
#define LENGTH 45

/* Prototypes */
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *speller);
unsigned int size(void);
bool unload(void);

/* --------------------------------- */

/* constant for hash table size */
const unsigned int N = 100000;

/* node struct for linked list */
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

/* hash table (initialized to NULL by default since global) */
static node *table[100000];

/* word counter */
static unsigned int word_count = 0;

/* forward declaration of helper used on error cleanup */
static void free_table(void);

/* hash function (djb2 variant, case-insensitive) */
unsigned int hash(const char *word)
{
    unsigned long h = 5381;
    unsigned char c;
    while ((c = (unsigned char) *word++))
    {
        h = ((h << 5) + h) + tolower(c); /* h * 33 + tolower(c) */
    }
    return (unsigned int)(h % N);
}

/* load speller into memory, return true if successful */
bool load(const char *speller)
{
    /* initialize table explicitly (not strictly required for globals, but clear) */
    for (unsigned int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    word_count = 0;

    FILE *file = fopen(speller, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%45s", word) != EOF) /* limit read to avoid overflow */
    {
        /* allocate node */
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            /* memory allocation failed -> cleanup and return false */
            fclose(file);
            free_table();
            return false;
        }

        /* copy the word into node (safe) */
        strncpy(n->word, word, LENGTH);
        n->word[LENGTH] = '\0'; /* ensure null-terminated */

        /* insert into table (at head of linked list) */
        unsigned int h = hash(n->word);
        n->next = table[h];
        table[h] = n;

        word_count++;
    }

    fclose(file);
    return true;
}

/* check whether word is in speller (case-insensitive) */
bool check(const char *word)
{
    if (word == NULL)
        return false;

    /* create lowercase copy to pass to hash (and for comparison) */
    char lower[LENGTH + 1];
    size_t len = strlen(word);

    /* if input word is longer than LENGTH, immediately return false */
    if (len > LENGTH)
        return false;

    for (size_t i = 0; i < len; i++)
    {
        lower[i] = tolower((unsigned char)word[i]);
    }
    lower[len] = '\0';

    unsigned int h = hash(lower);
    node *cursor = table[h];
    while (cursor != NULL)
    {
        /* compare case-insensitively */
        if (strcasecmp(cursor->word, lower) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

/* number of words loaded */
unsigned int size(void)
{
    return word_count;
}

/* unload speller from memory, return true if successful */
bool unload(void)
{
    free_table();
    /* after freeing, zero counters and pointers for safety */
    word_count = 0;
    for (unsigned int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    return true;
}

/* helper: free every node in the table */
static void free_table(void)
{
    for (unsigned int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL;
    }
}

/* Optional: main for quick local testing (uncomment to test) */
/*
int main(void)
{
    if (!load("large.txt"))
    {
        fprintf(stderr, "Failed to load speller\n");
        return 1;
    }
    printf("Loaded %u words\n", size());

    printf("check(\"hello\"): %s\n", check("hello") ? "FOUND" : "NOT FOUND");
    printf("check(\"HELLO\"): %s\n", check("HELLO") ? "FOUND" : "NOT FOUND");
    printf("check(\"pneumonoultramicroscopicsilicovolcanoconiosis\"): %s\n",
           check("pneumonoultramicroscopicsilicovolcanoconiosis") ? "FOUND" : "NOT FOUND");

    unload();
    return 0;
}
*/