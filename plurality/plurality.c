#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

bool checkvote(char *nameofcandidate, char*namevoted);

typedef struct {
    char nameofcandidate[20];
    int numberofvotes;
} candidate;

int main(int argc, char *argv[])
{

    candidate candidates[MAX];

    

    char namevoted[MAX];
    int numberofvotes;

    printf("number of votes: ");
    scanf("%d", &numberofvotes);

    for (int j = 0; j < numberofvotes; j++)
    {
        printf("vote: ");
        scanf("%s", namevoted);

        for (int k = 0; k < argc; k++)
        {
            if (checkvote(argv[k+1], namevoted))
            {
                printf("valid vote.\n");
                //add a vote to struct
            }
        }
    }

    printf("END\n");
    

}

bool checkvote(char *nameofcandidate, char*namevoted)
{
    if (strcmp(nameofcandidate, namevoted) == 0) return true;
    else return false;
}
