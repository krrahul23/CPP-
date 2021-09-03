#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *p = "Hello my name is";
    char *q = malloc(strlen(p) + 1);
    strcpy(q, p);
    printf("%s\n", q);
    printf("%s\n", p);
    free(q);
    return 0;
}