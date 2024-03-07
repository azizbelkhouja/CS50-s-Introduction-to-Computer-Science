#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {

    char cardnumber[16];

    printf("Number: ");

    while(1) {
        scanf("%s", cardnumber);
        if ( (strlen(cardnumber) == 15)) {
            if ((int)cardnumber[0] == 3) {
                if ((int)cardnumber[1] == 4 || (int)cardnumber[1] == 7) {
                    printf("American Express\n");
                    break;
                }
            }
        } else  if ( (strlen(cardnumber) == 16)) {
                    if ((int)cardnumber[0] == 5) {
                        if ((int)cardnumber[1] >= 1 || (int)cardnumber[1] <= 5) {
                            printf("VISA\n");
                            break;
                        }
                    } else if ((int)cardnumber[0] == 4) printf("MASTERCARD\n");
                } else  if ( (strlen(cardnumber) == 13)) {
                            if ((int)cardnumber[0] == 4) {
                                    printf("MASTERCARD\n");
                                    break;
                                }
                            }
    }
    printf("END\n");


}