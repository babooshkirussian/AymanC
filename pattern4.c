#include <stdio.h>
int min(int a,int b)
{
    if (a>b)
    {
        return b;
    }
    else{
        return a;
    }
}
int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    int size=n*2-1;
    for (int i=0;i<size;i++)//rows
    {
        for (int j=0;j<size;j++)//columns
        {
            int posix=j;
            int posiy=i;
            int negix=size-j-1;
            int negiy=size-i-1;
            int min_distance=min(posix,posiy);
            printf("%i ",n-min_distance);
        }
        printf("\n");
    }
}