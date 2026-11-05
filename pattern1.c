#include <stdio.h>
int main(){
    int itt;
    printf("Enter the number of itterations ");
    scanf("%i",&itt);
    for (int i=0;i<=itt;i++){
        for (int j=0;j<=i;j++){
            printf("*");
        }
        printf("\n");
        }
    return 0;    
}
