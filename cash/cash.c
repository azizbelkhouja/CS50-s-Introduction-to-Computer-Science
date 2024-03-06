#include <stdio.h>
#include <ctype.h>

int main(void) {
    int change;
    int n;

    printf("change owed: ");

    // Keep asking for input until a valid change is entered
    while (1) {
        // Try to read an integer
        if (scanf("%d", &change) != 1) {
            // If scanf fails, clear input buffer
            while (getchar() != '\n'); // Clear input buffer
            printf("change owed: ");
            continue;
        }


        // Check if the input is within the desired range and there's no trailing characters
        if (change >= 0 && getchar() == '\n') {
            break; // Valid input, exit the loop
        } else {
            // Invalid input, clear input buffer
            while (getchar() != '\n'); // Clear input buffer
            printf("change owed: ");
        }
    }
        if (change == 0) {
            printf("0\n");
            return 0;
        }
        
        n = change / 25;
        change = change % 25;

        if (change != 0) {
        n = n + (change/10);
        change = change % 10;
        }

       if (change != 0) {
        n = n + (change/5);
        change = change % 5;
        }

        if (change != 0) {
        n = n + (change/1);
        }

        printf("%i\n", n);

}