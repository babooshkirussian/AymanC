#include <stdio.h>
int LCM(int a,int b)
{
    int check=0;
    int smallest;
    if (a>b)
    {
        smallest=b;
    }
    else
    {
        smallest=a;
    }
    for(int i=2;i<=smallest/2;i++)
    {
        if ((a%i==0) && (b%i==0))
        {
            return i;
            check=1;
        }
        else{
            continue;
        }
        return check;
    }
}
int main()
{
    printf("%d",LCM(16,111));
}