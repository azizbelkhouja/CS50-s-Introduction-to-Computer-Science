#include <stdio.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
    
    if (argc != 2 || !isdigit(*argv[1])) printf("Usage: ./caesar key");


}