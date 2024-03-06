#include <stdio.h>
#include <ctype.h>

int main(void) {
    int number;

    printf("enter a number from 1 to 8: ");

    // Keep asking for input until a valid number is entered
    while (1) {
        // Try to read an integer
        if (scanf("%d", &number) != 1) {
            // If scanf fails, clear input buffer
            while (getchar() != '\n'); // Clear input buffer
            printf("enter a number from 1 to 8: ");
            continue;
        }

        // Check if the input is within the desired range and there's no trailing characters
        if (number >= 1 && number <= 8 && getchar() == '\n') {
            break; // Valid input, exit the loop
        } else {
            // Invalid input, clear input buffer
            while (getchar() != '\n'); // Clear input buffer
            printf("enter a number from 1 to 8: ");
        }
    }

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            printf(" ");
        }
        for (int k=0;k<i+1;k++) {
            printf("#");
        }
        printf("  ");

        for (int k=0; k < i + 1; k++) {
            printf("#");
        }

        printf("\n");
    }


}
