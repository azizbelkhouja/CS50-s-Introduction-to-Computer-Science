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

    for (int i = 0; i < argc - 1; i++) 
    {
        strcpy(candidates[i].nameofcandidate, argv[i+1]);
        candidates[i].numberofvotes = 0;
    }



    char namevoted[MAX];
    int numberofvotes;
    int ValidVotesCounter = 0;

    printf("number of votes: ");
    scanf("%d", &numberofvotes);

    while (ValidVotesCounter < numberofvotes)
    {
        printf("vote: ");
        scanf("%s", namevoted);

        for (int j = 0; j < argc - 1; j++)
        {
            if (checkvote(candidates[j].nameofcandidate, namevoted))
            {
                ValidVotesCounter++;
                candidates[j].numberofvotes++;
                continue;
            }
            printf("invalid vote.\n");
        }
    }

    printf("END\n");
    

}

bool checkvote(char *nameofcandidate, char*namevoted)
{
    if (strcmp(nameofcandidate, namevoted) == 0) return true;
    else return false;
}
