#include <stdio.h>
int factorial(int n)
{
    int total=1;
    for (int i=1;i<=n;i++)
    {
        total*=i;
    }
    return total;
}
int main()
{
    printf("%i",factorial(9));
}