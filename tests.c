#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    //testing the (int) thing
    char num = '7';

    printf("%c\n", num);
    printf("%i\n", num);
    printf("%i\n", (int)num);

    //char to int
    int d = 7;

    printf("\n%i\n", d);

    if ((num - '0') == d) printf("\nwe made it\n");
    else printf("\nstill debugging\n");

    
    printf("%lld\n", (long long)pow(10, 13));


}