#include <stdio.h>
//program to get familiar with pointers
//changing the values of x and y at their pointer
int abs(int a)
{
    if (a<0)
    {
        a=a*-1;
        return a;
    }
    else 
    {
        return a;
    }
}
void change(int*a,int*b)
{
    int tem1=*a;
    int tem2=*b;
    *a=tem1+tem2;
    *b=abs(tem1-tem2);
}
int main()
{
    int x;
    int y;
    int *p;
    int *q;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Enter y: ");
    scanf("%d",&y);
    p=&x;
    q=&y;
    change(p,q);
    printf("new x: %d\n",x);
    printf("new y: %d\n",y);
}