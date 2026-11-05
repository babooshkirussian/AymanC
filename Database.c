#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    struct Student
    {
        int id;
        char name[20];
        int mark;
    };
    struct Student students[20];
    int n;
    printf("Enter the no of records you want to enter ");//create part of CRUD
    scanf("%i",&n);
    for (int i=0;i<n;i++)
    {
        printf("Enter the id no  of rec %i ",i+1);
        scanf("%i",&students[i].id);
        getchar();
        printf("Enter the name  of rec %i ",i+1);
        fgets(students[i].name,sizeof(students[i].name),stdin);
        printf("Enter the mark  of rec %i ",i+1);
        scanf("%i",&students[i].mark);
    }
    for (int i=0;i<n;i++)
    {
        printf("the id of student %i is %i",i,students[i].id);
        printf("the name of student %i is %s",i,students[i].name);
        printf("the mark of student %i is %i",i,students[i].mark);
    }
    int choice;
    printf("Read record(1)\nUpdate record(2)\nDelete record(3)\nEnter your choice: ");
    scanf("%i",&choice);
    if (choice==1)//read part of crud
    {
        int search_id;
        printf("Enter the id of the rec you want to read: ");
        scanf("%i",&search_id);
        for (int i=0;i<n;i++)
        {
            if (search_id==students[i].id)
            {
                printf("id: %i\nname: %s\nmark: %i",students[i].id,students[i].name,students[i].mark);
            }
        }

    }
    if (choice==2)//update part of crud
    {
        int search_id;
        printf("Enter the id of the rec you want to update: ");
        scanf("%i",&search_id);
        for (int i=0;i<n;i++)
        {
            if (search_id==students[i].id)
            {
                printf("Enter the new id of rec");
                scanf("%i",&students[i].id);
                getchar();
                printf("Enter the name  of rec ");
                fgets(students[i].name,sizeof(students[i].name),stdin);
                printf("Enter the mark  of rec ");
                scanf("%i",&students[i].mark);
            }
        }
    }
    if (choice==3)
    {
        int search_id;
        printf("Enter the id of the rec you want to update: ");
        scanf("%i",&search_id);
        for (int i=0;i<n;i++)
        {
            if (search_id==students[i].id)
            {
                for (int s=i;s<n-1;s++)
                {
                    students[s]=students[s+1];
                }
            }
        }
    }
}