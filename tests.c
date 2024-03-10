#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    int worth[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    char alphabet[26];
    int tot = 0;
    char player1[20], player2[20];

    printf("player1: ");
    scanf("%s", player1);
    
    printf("player2: ");
    scanf("%s", player2);

    //Filling the alphabet array
    for (int i = 0; i < 26; i++) {

        alphabet[i] = 65 + i;

    }

    for (int j = 0; j < strlen(player1); j++) {
        for (int k = 0; k < 26; k++) {
            if (toupper(player1[j]) == alphabet[k]) tot = tot + worth[k];
        }
    }

    printf("%i", tot);

}