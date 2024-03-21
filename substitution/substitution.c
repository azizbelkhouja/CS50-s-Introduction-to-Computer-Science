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

    printf("key: %s\n", key);

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

    for (int j = 0; j < 26; j++)
    {
        for (int k = j + 1; k < 26; k++)
        {
            if (tolower(key[j]) == tolower(key[k]))
            {
                printf("key must not contain repeated characters.\n");
                return 4;
            }
        }
    }

    char plaintext[50], ciphertext[50];
    int m;

    printf("plaintext: ");
    fgets(plaintext, 50, stdin);

    for (int l = 0; l < strlen(plaintext); l++) 
    {
        
            if (islower(plaintext[l]))
            {
                for (m = 0; m < 26; m++)
                {
                    if (plaintext[l] == tolower(key[m]))
                    {
                        ciphertext[l] = tolower(key[m]);
                    }
                }
            } 
            else if (isupper(plaintext[l]))
                {
                    for (m = 0; m < 26; m++)
                    {
                        if (plaintext[l] == toupper(key[m]))
                        {
                            ciphertext[l] = toupper(key[m]);
                        }
                    }
                }
            else ciphertext[l] = plaintext[l];
    }
    ciphertext[strlen(plaintext)-1] = '\0';

    printf("ciphertext: %s\n", ciphertext);




}