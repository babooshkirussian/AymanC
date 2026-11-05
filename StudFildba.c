#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//The idea for this database is to first load all the text from a database into an array perform any CRUD operation and then 
//rewrite the origianl with the updated version
//first file handling
struct Student
{
    int id;
    char name[20];
    int marks;
};
struct Student students[100];
int n=0;
void loadstudents()
{
    FILE *file;
    file=fopen("studataba.txt","r");
    if (file==NULL)
    {
        printf("could'nt open file \n");
        return;
    }
    char line[100];
    while (fgets(line,sizeof(line),file)!=NULL)
    {
        if (sscanf(line,"%i %19s %i",&students[n].id,students[n].name,&students[n].marks)==3)
        {
            n++;
        }
        else
        {
            printf("Invalid line: %s",line);
        }
    }
    fclose(file);
}   
void write()
{
    //writing the details of the struct into the file
    FILE *file;
    file=fopen("studataba.txt","w");
    for (int i=0;i<n;i++)
    {
        fprintf(file,"%i %s %i\n",students[i].id,students[i].name,students[i].marks);
    }
    fclose(file);
    printf("written\n");
}
void intiate()
{
    printf("Enter the number of records you want to enter: \n");
    scanf("%i",&n);
    for (int i=0;i<n;i++)
    {
        printf("Enter ID %i: \n",i);
        scanf("%i",&students[i].id);
        printf("Enter name %i: \n",i);
        scanf("%19s",students[i].name);
        printf("Enter marks %i: \n",i);
        scanf("%i",&students[i].marks);
    }
    printf("Details Intiated\n");
}
//CRUD programing
void Create()
{
    printf("Enter details\n");
    printf("ID %i: \n",n);
    scanf("%i",&students[n].id);
    printf("Name %i: \n",n);
    scanf("%19s",students[n].name);
    printf("Marks %i: ",n);
    scanf("%i",&students[n].marks);
    n++;
    while (true)
    {
        char choice;
        printf("Do you want to add more records(y/n): \n");
        scanf(" %c",&choice);
        if (choice=='y' || choice=='Y')
        {
            printf("Enter details\n");
            printf("ID %i: \n",n);
            scanf("%i",students[n].id);
            printf("Name %i: \n",n);
            scanf("%19s",students[n].name);
            printf("Marks %i: ",n);
            scanf("%i",&students[n].marks);
            n++;
        }
        else
        {
            return;
        }
    }
}
void Read()
{
    int searchid;
    printf("Enter the search id: \n");
    scanf("%i",&searchid);
    int found;
    found=1;
    for (int i=0;i<n;i++)
    {
        if (searchid==students[i].id)
        {
            printf("id: %i\nname: %s\nmark: %i\n",students[i].id,students[i].name,students[i].marks);
            found=0;
        }
    }
    if (found==1)
    {
        printf("Not found\n");
    }
}
void Update()
{
    int searchid;
    printf("Enter the search id: \n");
    scanf("%i",&searchid);
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
            scanf("%i",&students[i].marks);
            found=0;
        }
    }
    if (found==1)
    {
        printf("Not found\n");
    }
}
void Delete()
{
    int found=0;
    int search_id;
    printf("Delete ID: \n");
    scanf("%i",&search_id);
    for (int j=0;j<n;j++)
    {
        if (search_id==students[j].id)
        {
            found=1;
        }
    }
    if (found==1)
    {
        for (int i=0;i<n;i++)
        {
            if (search_id==students[i].id);
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
}
void CRUDmanager()
{
    int choice3;
    printf("Which operation would you like to perform on the database: \nCreate(1)\nRead(2)\nUpdate(3)\nDelete(4)\n");
    scanf("%i",&choice3);
    if (choice3==1)
    {
        Create();
    }
    else if (choice3==2)
    {
        Read();
    }
    else if (choice3==3)
    {
        Update();
    }
    else if (choice3==4)
    {
        Delete();
    }
    else
    {
        printf("Wrong choice please try again\n");
    }
}
int main()
{
    printf("Welcome to the Student Database \n");
    int choice1;
    printf("Would you like to: \nAcess the previous database(1)\nCreate a new database(2)\n");
    scanf("%i",&choice1);
    if (choice1==1)
    {
        loadstudents();
    }
    else if (choice1==2)
    {
        intiate();
    }
    else
    {
        printf("Wrong\n");
        return 0;
    }
    char choice2;
    CRUDmanager();
    while (true)
    {
        printf("Do you want to exit database(y/n): \n");
        scanf(" %c",&choice2);
        if (choice2=='y' || choice2=='Y' )
        {
            CRUDmanager();
        }
        else
        {
            write();
            return false;
        }
    }
}