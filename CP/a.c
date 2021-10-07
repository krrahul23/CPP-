#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void m(int k)
{
    printf("hi");
}
void m(double k)
{
    printf("hello");
}

int main()
{
    m(3);
    return 0;
}