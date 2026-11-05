#include <stdio.h>
int main()
{
    int n;
    printf("pattern making\n");
    scanf("%i",&n);
    int size=n*2-1;
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
}