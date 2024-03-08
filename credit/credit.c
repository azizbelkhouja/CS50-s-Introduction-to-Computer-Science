#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int length(long cardnumber);
bool amex(long cardnumber);
bool mastercard(long cardnumber);
bool visa13(long cardnumber);
bool visa16(long cardnumber);

int main(void) {
    long cardnumber;

    printf("Number: ");

    while(1) {

    if (scanf("%ld", &cardnumber) != 1) {
            // If scanf fails, clear input buffer
            while (getchar() != '\n'); // Clear input buffer
            printf("Number: ");
            continue;
        }

    int n = length(cardnumber);
    printf("%i\n", n);



    }

   
}


//length of the card number 
int length(long cardnumber) {

    int length = 0;
    while (cardnumber != 0) {
        cardnumber = cardnumber / 10;
        length++;
    }
    return length;
}

//card type
bool amex(long cardnumber) {
    if (cardnumber / pow(10, 13) == 34 || cardnumber / pow(10, 13) == 37) {
        return true;
    } else return false;
}
bool mastercard(long cardnumber) {
    if (cardnumber / pow(10, 14) >= 51 && cardnumber / pow(10, 14) <= 55) {
        return true;
    } else return false;
}
bool visa13(long cardnumber) {
    if (cardnumber / pow(10, 12) == 4) {
        return true;
    } else return false;
}
bool visa16(long cardnumber) {
    if (cardnumber / pow(10, 15) == 4) {
        return true;
    } else return false;
}

