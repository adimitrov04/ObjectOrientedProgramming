#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_WORD_LEN = 256;
const int MAX_WORD_COUNT = 1000;

// Function to copy string without newline character
void strwcpy (char* dest, const char* src)
{
    while (*src && (*src != '\r') && (*src != '\n'))
    {
        *dest = *src;

        dest++;
        src++;
    }

    *dest = '\0';
}

char** createWordList (FILE* file, int* wordCount)
{
    if (file == 0)
        return 0;

    char** output = malloc(MAX_WORD_COUNT * sizeof(char*));
    
    for (int i = 0; i < MAX_WORD_COUNT; i++)
    {
        if (feof(file))
            break;

        output[i] = malloc(MAX_WORD_LEN * sizeof(char));

        char* buffer = malloc(MAX_WORD_LEN * sizeof(char));
        fgets(buffer, MAX_WORD_LEN, file);
        strwcpy(output[i], buffer);
        free(buffer);

        (*wordCount)++;
    }

    return output;
}

int inList (char* word, char** listToSearch, const int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        if (strcmp(word, listToSearch[i]) == 0)
            return 1;
    }

    return 0;
}

void printList (char** list, const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s", list[i]);
    }
}

void freeList (char** list, const int size)
{
    for (int i = 0; i < size; i++)
        free(list[i]);
    
    free(list);
}

int main ()
{
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    
    if (dictionary_file == 0)
    {
        return -1;
    }

    FILE *input_file = fopen("input.txt", "r");

    if (input_file == 0)
    {
        fclose(dictionary_file);
        return -1;
    }

    int dictionarySize = 0;
    char** dictionary = createWordList(dictionary_file, &dictionarySize);
    
    if (dictionary == 0)
    {
        fclose(dictionary_file);
        fclose(input_file);

        return -2;
    }

    fclose(dictionary_file);

    int inputSize = 0;
    char** input = createWordList(input_file, &inputSize);

    if (input == 0)
    {
        fclose(input_file);
        freeList(dictionary, dictionarySize);

        return -2;
    }
    
    fclose(input_file);

    for (int i = 0; i < inputSize; i++)
    {
        if (inList(input[i], dictionary, dictionarySize) == 0)
        {
            FILE *missing_file = fopen("missing.txt", "a");
            if (missing_file == 0)
                break;

            fputs(input[i], missing_file);
            fputc('\n', missing_file);
            
            fclose(missing_file);
        }
    }

    freeList(dictionary, dictionarySize);
    freeList(input, inputSize);

    return 0;
}