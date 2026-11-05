#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int size=n*2-1;
    for (int i=0;i<size;i++)//row
    {
        for (int j=0;j<size;j++)
        {
            printf(j);
        }
        printf("\n");
    }
    return 0;
}