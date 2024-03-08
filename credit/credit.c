#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {

    char cardnumber[16];

    printf("Number3: ");

    while(1) 
    {

        scanf("%s", cardnumber);
        int length = strlen(cardnumber);

        for (int i=0; i<length; i++) 
        {
            if (!isdigit(cardnumber[i]))
            {
                while (getchar() != '\n');
                printf("Number: ");
            }
        }



        //Card type check
        if ( (length == 15)) {
            if ((cardnumber[0] - '0') == 3) {
                if ((cardnumber[1] - '0') == 4 || (cardnumber[1] - '0') == 7) {
                    printf("American Express\n");
                    break;
                }
            }
        } else  if ( (length == 16)) {
                    if ((cardnumber[0] - '0') == 5) {
                        if ((cardnumber[1] - '0') >= 1 || (cardnumber[1] - '0') <= 5) {
                            //printf("VISA\n");
                            break;
                        }
                    } else  if ((cardnumber[0] - '0') == 4) {
                            //printf("MASTERCARD\n");
                            break;
                            }
                } else  if ( (length == 13)) {
                            if ((cardnumber[0] - '0') == 4) {
                                    //printf("MASTERCARD\n");
                                    break;
                                }
                            }
    }
    printf("testEND\n");


}