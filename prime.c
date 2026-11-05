#include <stdio.h>
int main()
{
    //program to find prime numbers
    int n;
    scanf("%d",&n);
    int flag=0;
    for (int i=2;i<n;i++)
    {
        if (n==2)
        {
            flag=1;
            break;
        }
        else 
        {
            if (n%i==0)
            {
                flag=1;
                break;
            }
        }
    }
    if (flag==1)
    {
        printf("not prime");
    }
    else{
        printf("prime");
    }
}