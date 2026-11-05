#include <stdio.h>
#include <stdlib.h>
int main()
{
    //creating dynamic array
    int *arr;
    arr=malloc(5*sizeof(int));
    //putting values into array
    for(int i=0;i<5;i++)
    {
        arr[i]=0;
        arr[i]=arr[i]+i;
        arr[i]=arr[i]*10;
        printf("%d ",arr[i]);
    }
    //now test realloc
    arr=realloc(arr,10*sizeof(int));
    printf("\n");
    for(int i=0;i<10;i++)
    {
        arr[i]=0;
        arr[i]=i+1;
        arr[i]=arr[i]*11;
        printf("%d ",arr[i]);
    }
    return 0;

}
