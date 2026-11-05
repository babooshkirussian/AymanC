#include <stdio.h>
//code to show the functionality and logic behind pointers
//first we intialize 3 values
int main()
{
    int x=50;
    int y=100;
    int *p;//this is how we intialize a pointer alternatively int *p=&z;
    p=&x;//setting the pointer to point to address of x
    printf("intially pointer has the value of x which is %d\n",*p);
    p=&y;
    printf("Now %d\n",*p);
    return 0;


}