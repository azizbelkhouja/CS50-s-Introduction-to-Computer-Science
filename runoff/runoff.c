#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char *nameofcandidate[10];
    int numberofvotes;
    bool eliminated;
}candidate;

int main(int argc, char *argv[])
{
    if (argc > 9 ) {printf("number of candidates must be under 9\n"); return 1;}
    if (argc < 2 ) {printf("insert atleast one candidate\n"); return 1;}


}