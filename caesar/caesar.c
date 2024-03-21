#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

int main (int argc, char *argv[])
{

    int n = strlen(argv[1]);
    int key;
    char str[MAX], plaintext[MAX], ciphertext[MAX];
    int length, alphabeticalindex;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (argc == 2) 
    {
        strcpy(str, argv[1]);

        for (int i = 0; i < n; i++)
        {
            if (!isdigit(str[i]))
            {
                printf("key must be only digits\n");
                return 2;
            }
        }
    }

    key = atoi(str);

    printf("plain text: ");
    fgets(plaintext, MAX, stdin);


    length = strlen(plaintext);

    for (int j = 0; j < length; j++)
    {
        if (isupper(plaintext[j]))
        {
            alphabeticalindex = plaintext[j] - 65;
            ciphertext[j] = ((alphabeticalindex + key) % 26) + 65;
        }
        else if (islower(plaintext[j]))
            {
                alphabeticalindex = plaintext[j] - 97;
                ciphertext[j] = ((alphabeticalindex + key) % 26) + 97;
            }
        else ciphertext[j] = plaintext[j];
    }
    ciphertext[length-1] = '\0';

    printf("\nciphertext is \"%s\"\n", ciphertext);

}