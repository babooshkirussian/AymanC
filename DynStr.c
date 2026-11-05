#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str1[20];
    printf("Enter string: ");
    fgets(str1,sizeof(str1),stdin);
    for(int i=0;i<strlen(str1);i++)
    {
        if(str1[i]>='A' && str1[i]<='Z')
        {
            str1[i]=str1[i]+32;
        }
        printf("%c",str1[i]);
    }
    return 0;

}