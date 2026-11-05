#include <stdio.h>
int main()
{
    printf("Hello\n");
    int *P;
    *P=10;
    printf("%d\n",*P);
    *P++;
    printf("%d\n",*P);
    return 0;
}