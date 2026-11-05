#include <stdio.h>
int main()
{
    //new pattern
    //*
    //**
    //***
    int times;
    printf("Enter the no times");
    scanf("%i",&times);
    for (int i=0;i<=times;i++)
    {
        for (int j=times;j>=0;j--)
        {
            printf("*");
        }
        printf("\n");
    }
}