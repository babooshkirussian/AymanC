#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Student
    {
        int id;
        char name[20];
        int mark;
    };
struct Student students[20];
int n=0;

int searchinfo()
{
    int search_id;
    printf("Enter the id of the rec you want to read: ");
    scanf("%i",&search_id);
    return search_id;
}
void create()//create part of crud
{
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
}
int get_choice()
{
    int choice;
    printf("Read record(1)\nUpdate record(2)\nDelete record(3)\nEnter your choice: ");
    scanf("%i",&choice);
    return choice;
}
void read(struct Student students[20],int n)//read part of crud
{
    int searchid;
    searchid=searchinfo();
    int found;
    found=1;
    for (int i=0;i<n;i++)
    {
        if (searchid==students[i].id)
        {
            printf("id: %i\nname: %smark: %i\n",students[i].id,students[i].name,students[i].mark);
            found=0;
        }
    }
    if (found==1)
    {
        printf("Not found\n");
    }
}
void update(struct Student students[20],int n)//update part of crud
{
    int searchid;
    searchid=searchinfo();
    int found;
    found=1;
    for (int i=0;i<n;i++)
    {
        if (searchid==students[i].id)
        {
            printf("Enter the new id of rec");
            scanf("%i",&students[i].id);
            getchar();
            printf("Enter the name  of rec ");
            fgets(students[i].name,sizeof(students[i].name),stdin);
            printf("Enter the mark  of rec ");
            scanf("%i",&students[i].mark);
            found=0;
        }
    }
    if (found==1)
    {
        printf("Not found\n");
    }
}
void delete(struct Student students[20],int n)
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
    n--;
    printf("Record sucessfully deleted\n");
}
int choice()
{
    int choice;
    printf("\nRead record(1)\nUpdate record(2)\nDelete record(3)\nEnter your choice: ");
    scanf("%i",&choice);
    return choice;
}
int main()
{
    printf("Welcome to student database created by Ayman\n");
    create();

    while (true)
    {
        char dec;
        printf("Do you want to access student database(y/n)");
        scanf(" %c",&dec);
        if (dec=='y'||dec=='Y')
        {
            int cho;
            cho=choice();
            if (cho==1)
            {
                read(students,n);
            }
            if (cho==2)
            {
                update(students,n);
            }
            if (cho==3)
            {
                delete(students,n);
            }
            
        }
        else
        {
            printf("GoodBye see you later");
            return false;
        }
    }
}
