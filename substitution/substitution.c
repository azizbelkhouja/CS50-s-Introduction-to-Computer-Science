#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 27

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    char key[MAX];
    strcpy(key, argv[1]);

    if (strlen(key) != 26) 
    {
        printf("key must contain 26 characters.\n");
        return 2;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("key must only contain alphabetic characters.\n");
            return 3;
        }
    }

    

}