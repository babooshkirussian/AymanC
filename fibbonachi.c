#include <stdio.h>
int main()
{
    int n;
    printf("Enter Number for fibbo seq: ");
    scanf("%d",&n);
    int first=0,second=1,next=0;
    for (int i=0;i<=n;i++)
    {
        if (i==1)
        {
            next=1;
        }
        else if (i==0)
        {
            next=0;
        }
        
        else
        {
            next=first+second;
            first=second;
            second=next;
        }
        printf("%d ",next);
    }
}