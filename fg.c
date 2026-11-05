#include <stdio.h>
int main(){
    //program to print pattern 2
    //1234
    //1234
    //1234
    //1234
    for (int i=0;i<5;i++){
        for (int j=1;j<5;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}