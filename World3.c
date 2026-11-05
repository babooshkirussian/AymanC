#include <stdio.h>
int main()
{
    int n;
    printf("Enter the the no of meows: ");
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        printf("Meow ^o^\n");
        printf("%i\n",i);
    }
    return 0;
}
