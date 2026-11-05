#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct Student
{
    int id;
    char name[20];
    int marks;
};
int n=0;
struct Student students[20];
void write()
{
    //Today we will playing with files
    FILE *pointer;
    pointer=fopen("test.txt","w");
    for (int i=0;i<n;i++)
    {
        fprintf(pointer,"%i %s %i\n",students[i].id,students[i].name,students[i].marks);
    }
    fclose(pointer);
    printf("write\n");
}
void read()
{
    //reading
    FILE *pointer;
    pointer=fopen("test.txt","r");
    char sentence[100];
    while (fgets(sentence,100,pointer)!=NULL)
    {
        printf("%s",sentence);
    }
    fclose(pointer);
    printf("read\n");
}
void credaba()
{
    printf("Enter the number of records: \n");
    scanf("%i",&n);
    for (int i=0;i<n;i++)
    {
        printf("id %i: ",i+1);
        scanf("%i",&students[i].id);
        printf("name %i: ",i+1);
        scanf(" ");
        fgets(students[i].name,20,stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("marks %i: ",i+1);
        scanf("%i",&students[i].marks);
    }
}
int main()
{
    credaba();
    write();
    read();
}
