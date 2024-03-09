#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    int m = 0, n = 0;
    long long cardnumber = 4003600000000014;

    //378282246310005
    //4003600000000014

    while (cardnumber != 0) {

        printf("card number: %lld\n", cardnumber);

        m = m + (cardnumber % 10);
        printf("m= %i\n", m);

        cardnumber = cardnumber / 10;
        printf("card number: %lld\n", cardnumber);
        
        n = n + ((cardnumber % 10) * 2);
        printf("n= %i\n", n);

        cardnumber = cardnumber / 10;
        printf("card number: %lld\n", cardnumber);

        printf("\n");

    }

}