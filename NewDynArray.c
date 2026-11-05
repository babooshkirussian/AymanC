#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr;
    arr=(int*)malloc(5*sizeof(int));
    for (int i=0;i<5;i++)
    {
        arr[i]=0;
        arr[i]=arr[i]+i+1;
        printf("%i",arr[i]);
    }
    return 0; 
}