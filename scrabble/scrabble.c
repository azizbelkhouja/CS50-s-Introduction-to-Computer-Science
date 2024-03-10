#include <stdio.h>
#include <string.h>
#include <ctype.h>

int score(char *player);

int main(void) {

    //asking the users for input
    char player1[100], player2[100];

    printf("player1: ");
    scanf("%s", player1);
    
    printf("player2: ");
    scanf("%s", player2);

    int p1 = score(player1);
    int p2 = score(player2);

    if (p1 > p2) {
        printf("player 1 WON!!!!\n");
    } else if (p1 < p2) {
        printf("player 2 WON!!!!\n");
    } else printf("DRAW\n");
    

    


}

int score(char *player) {

    int worth[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    char alphabet[26];
    int tot = 0;

    //Filling the alphabet array
    for (int i = 0; i < 26; i++) {

        alphabet[i] = 65 + i;

    }

    for (int j = 0; j < strlen(player); j++) {
        for (int k = 0; k < 26; k++) {
            if (toupper(player[j]) == alphabet[k]) tot = tot + worth[k];
        }
    }

    return tot;
}