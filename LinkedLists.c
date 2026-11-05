#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int number;
    struct node *next;
}node;
int main()
{
    node *list=NULL;
    for (int i=1;i<=3;i++)
    {
        node *n=malloc(sizeof(node));
        if (n==NULL)
        {
            return 1;
        }
        printf("Enter number %d for linked list: ",i);
        scanf("%d",&n->number);
        n->next=list;
        list=n;
    }
    node *ptr=list;
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->number);
        ptr=ptr->next;
    }
}
