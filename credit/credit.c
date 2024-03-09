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
    int temp = 0;

    while (cardnumber != 0) {

        m = m + (cardnumber % 10);

        cardnumber = cardnumber / 10;
        
        if (((cardnumber % 10) * 2) > 9) {
            temp = (cardnumber % 10) * 2;
            n = n + (temp / 10);
            n = n + (temp % 10);
        } else n = n + ((cardnumber % 10) * 2);
        
        cardnumber = cardnumber / 10;

    }

    return n + m;
}

