#include <stdio.h>
void test()
{
    printf("function text");
}
int main()
{
    printf("does this appear on the same line as: ");
    printf("this, what about loops: ");
    for (int i=0;i<10;i++)
    {
        printf("meow");
    }
    printf("what about in a function");
    test();
}