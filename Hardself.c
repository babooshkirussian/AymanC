#include <stdio.h>
int min(int a, int b) {
    return (a < b) ? a : b;
}
int main()
{
    //bascically every number has a coordination based on the distance from the center that is 1
    //we also need the size of this pattern (the no of rows/collumns) basically the side of the square pattern
    int n=4;
    int size=n*2-1;
    for (int i=0;i<size;i++)//the rows
    {
        for (int j=0;j<size;j++)//the columns
        {
            int posix=i;
            int negix=size-i-1;
            int posiy=j;
            
            int negiy=size-j-1;
            int small_distance=min(min(posix,negix),min(posiy,negiy));
            printf("%d ",n-small_distance);
        }
        printf("\n");
    }
}