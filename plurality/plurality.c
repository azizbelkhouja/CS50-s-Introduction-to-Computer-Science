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
    int numberofvotes, highestvote;
    int ValidVotesCounter = 0;
    bool ValideVote;

    printf("START\n");

    for (int i = 0; i < argc - 1; i++) 
    {
        strcpy(candidates[i].nameofcandidate, argv[i+1]);
        candidates[i].numberofvotes = 0;
        //printf("candidate %d is %s\n", i+1, candidates[i].nameofcandidate);
    }

    
    printf("number of votes: ");
    scanf("%d", &numberofvotes);

    while (ValidVotesCounter < numberofvotes)
    {
        ValideVote = false;
        printf("vote: ");
        scanf("%s", namevoted);

        for (int j = 0; j < argc - 1; j++)
        {
            if (checkvote(candidates[j].nameofcandidate, namevoted))
            {
                ValidVotesCounter++;
                candidates[j].numberofvotes++;
                ValideVote = true;
                break;
            }
        }

        if (!ValideVote) printf("Invalid Vote.\n");

    }

    highestvote = candidates[0].numberofvotes;

    for (int l = 0; l < argc - 2; l++) 
    {
        if (candidates[l].numberofvotes < candidates[l+1].numberofvotes)
        {
            highestvote = candidates[l].numberofvotes;
        }
    }

    for (int m = 0; m < argc - 1; m++) 
    {
        if (candidates[m].numberofvotes == highestvote) printf("%s\t", candidates[m].nameofcandidate);
    }
    
}

bool checkvote(char *nameofcandidate, char*namevoted)
{
    if (strcmp(nameofcandidate, namevoted) == 0) return true;
    else return false;
}
