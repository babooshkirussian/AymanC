#include <stdio.h>
int small(int a,int b)
{
    int c;
    (a>b)?(c=b):(c=a);
    return c;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    //program to show lcm,hcf
    //first we find hcf the highest common factor
    int hcf=1,lcm=a*b;
    for (int i=1;i<=small(a,b);i++)
    {
        if ((a%i==0)&&(b%i==0))
        {
            hcf=i;
        }
    }
    for(int i=small(a,b);i<=a*b;i++)
    {
        if ((i%a==0)&&(i%b==0))
        {
            lcm=i;
            break;
        }
    }
    printf("lcm: %d,hcf: %d",lcm,hcf);
}