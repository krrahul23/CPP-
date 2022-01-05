#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void len(char *s, char *t)
{
    unsigned int c = 0;
    int len = ((strlen(s) - strlen(t)) > c) ? strlen(s) : strlen(t);
    printf("%d", len);
}

int main()
{
    char *x = "abc";
    char *y = "defgh";
    len(x, y);321
    return 0;
}