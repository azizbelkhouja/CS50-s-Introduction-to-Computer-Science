#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{

    int length = strlen(argv[1]);
    int key;
    char *str, *text;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (argc == 2) 
    {
        strcpy(str, argv[1]);

        for (int i = 0; i < length; i++)
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
    scanf("%s", text);

    



}