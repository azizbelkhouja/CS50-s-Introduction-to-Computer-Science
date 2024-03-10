#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letters(char *text);
int words(char *text);
int sentences(char *text);
float coleman(int l, int w, int s);

int main(void) {

    char text[1000];

    printf("Text: ");
    fgets(text, 1000, stdin);

    int l = letters(text);
    printf("letters: %i\n", l);

    int w = words(text);
    printf("words: %i\n", w);
    
    int s = sentences(text);
    printf("sentences: %i\n", s);


    float index = coleman(l,w,s);
    printf("Grade: %.2f\n", index);



}

int letters(char *text) {
    
    int l = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) l = l + 1;
    }

    return l;
}

int words(char *text) {

    int l = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) l = l + 1;
    }

    return l;

}

int sentences(char *text) {

    int l = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (ispunct(text[i]) && text[i] != '\'') l = l + 1;
    }

    return l;

}

float coleman(int l, int w, int s) {

    float lw = ((float)l / w) * 100;
    float sw = ((float)s / w) * 100;

    float index = 0.0588*lw - 0.296*sw - 15.8;

    return index;
}