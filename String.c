#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//code to demonstate how strings work in C
int main()
{
    //creating the array
    char str1[]="hallelujahtotheworld";
    //Changing all to uppercase
    for (int i=0;i<strlen(str1);i++)
    {
        str1[i]=str1[i]-32;
        printf("%c",str1[i]);
    }
    return 0;

}