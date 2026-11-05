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
int n = 0;

int searchinfo()
{
    int search_id;

    printf("Enter the id of the record: ");
    scanf("%d", &search_id);

    return search_id;
}

void create()
{
    printf("Enter the number of records you want to enter: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the id of record %d: ", i + 1);
        scanf("%d", &students[i].id);

        getchar();

        printf("Enter the name of record %d: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);

        // Remove newline added by fgets
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Enter the mark of record %d: ", i + 1);
        scanf("%d", &students[i].mark);
    }
}

int choice()
{
    int choice;

    printf("\n1. Read record");
    printf("\n2. Update record");
    printf("\n3. Delete record");
    printf("\nEnter your choice: ");

    scanf("%d", &choice);

    return choice;
}

void read(struct Student students[20], int n)
{
    int searchid;
    searchid = searchinfo();

    for (int i = 0; i < n; i++)
    {
        if (searchid == students[i].id)
        {
            printf("\nID: %d", students[i].id);
            printf("\nName: %s", students[i].name);
            printf("\nMark: %d\n", students[i].mark);

            return;
        }
    }

    printf("Record not found.\n");
}

void update(struct Student students[20], int n)
{
    int searchid;
    searchid = searchinfo();

    for (int i = 0; i < n; i++)
    {
        if (searchid == students[i].id)
        {
            printf("Enter the new ID: ");
            scanf("%d", &students[i].id);

            getchar();

            printf("Enter the new name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);

            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter the new mark: ");
            scanf("%d", &students[i].mark);

            printf("Record updated successfully.\n");

            return;
        }
    }

    printf("Record not found.\n");
}

void delete_record(struct Student students[20], int *n)
{
    int search_id;

    printf("Enter the ID of the record you want to delete: ");
    scanf("%d", &search_id);

    for (int i = 0; i < *n; i++)
    {
        if (search_id == students[i].id)
        {
            // Shift everything after this record one position left
            for (int s = i; s < *n - 1; s++)
            {
                students[s] = students[s + 1];
            }

            (*n)--;

            printf("Record deleted successfully.\n");

            return;
        }
    }

    printf("Record not found.\n");
}

int main()
{
    printf("Welcome to student database created by Ayman\n");

    create();

    while (true)
    {
        char dec;

        printf("\nDo you want to access the student database? (y/n): ");
        scanf(" %c", &dec);

        if (dec == 'y' || dec == 'Y')
        {
            int cho = choice();

            if (cho == 1)
            {
                read(students, n);
            }
            else if (cho == 2)
            {
                update(students, n);
            }
            else if (cho == 3)
            {
                delete_record(students, &n);
            }
            else
            {
                printf("Invalid choice.\n");
            }
        }
        else if (dec == 'n' || dec == 'N')
        {
            printf("Goodbye!\n");
            return 0;
        }
        else
        {
            printf("Please enter y or n.\n");
        }
    }

    return 0;
}