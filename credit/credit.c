#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int cardlength(long long cardnumber);
bool amex(long long cardnumber);
bool mastercard(long long cardnumber);
bool visa13(long long cardnumber);
bool visa16(long long cardnumber);
int luhn(long long cardnumber, int length);

int main(void) {

    long long cardnumber;
    int n;

    printf("Number2: ");

    while(1) {

        if (scanf("%lld", &cardnumber) != 1) {
                // If scanf fails, clear input buffer
                while (getchar() != '\n'); // Clear input buffer
                printf("Number: ");
                continue;
            }

        n = cardlength(cardnumber);
        printf("%i\n", n);
        
        //verifying cards
        if (n == 15) {
            if (amex(cardnumber)) {
                printf("AMEX\n");
                break;
            }
        }
        if (n == 16) {
            if (mastercard(cardnumber)) {
                printf("MASTERCARD\n");
                break;
            } else if (visa16(cardnumber)) {
                printf("VISA\n");
                break;
            }
        }
        if (n == 13) {
            if (visa13(cardnumber)) {
                printf("VISA\n");
                break;
            }
        }


        while (getchar() != '\n'); // Clear input buffer
            printf("Number: ");
            continue;


    }

    //Luhn’s Algorithm
    int legit = luhn(cardnumber, n);
    printf("total of luhn's algorithm is: %i\n", legit);


}


//length of the card number 
int cardlength(long long cardnumber) {

    int length = 0;
    while (cardnumber != 0) {
        length++;
        cardnumber = cardnumber / 10;
    }
    return length;
}

//card type
bool amex(long long cardnumber) {
    if (cardnumber / (long long)pow(10, 13) == 34 || cardnumber / (long long)pow(10, 13) == 37) {
        return true;
    } else return false;
}
bool mastercard(long long cardnumber) {
    if (cardnumber / (long long)pow(10, 14) >= 51 && cardnumber / (long long)pow(10, 14) <= 55) {
        return true;
    } else return false;
}
bool visa13(long long cardnumber) {
    if (cardnumber / (long long)pow(10, 12) == 4) {
        return true;
    } else return false;
}
bool visa16(long long cardnumber) {
    if (cardnumber / (long long)pow(10, 15) == 4) {
        return true;
    } else return false;
}

//Luhn’s Algorithm
int luhn(long long cardnumber, int length) {
    
    int m = 0, n = 0;

    //378282246310005
    //4003600000000014

    //Now let’s add those products’ digits (i.e., not the products themselves) together:
    //2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

    while (cardnumber != 0) {

        m = m + (cardnumber % 10);

        cardnumber = cardnumber / 10;
        
        //if cardnumber*2 > 9 we split it, else all good
        n = n + ((cardnumber % 10) * 2);

        cardnumber = cardnumber / 10;

    }

    return n + m;
}

