#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void string_reverse1(char *);
char *string_reverse2(const char *);
int main() {
    char string[] = "NAVID";
    const char string2[] = "COOPER";
    string_reverse1(string);
    char *outstring = string_reverse2(string2);
    printf("%s\n", outstring); 
    free(outstring);
    return 1;
}


void string_reverse1(char *string)
{
    int i, j, c;
    int len = strlen(string);
    for (i = 0, j = len -1; i < j; i++, j--) 
    {
        c = string[i];
        string[i] = string[j];
        string[j] = c;
    }
}

char *string_reverse2(const char *string)
{
    int i, j, c;
    int len = strlen(string);
    char *outstring = (char *) malloc(len+1);
    for (i = 0, j = len -1; i < j; i++, j--) 
    {
        c = string[i];
        outstring[i] = string[j];
        outstring[j] = c;
    }
    outstring[len] = '\0';
    return outstring; 
}
