#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main()
{
    node *list=NULL;//this is the the start of the linked list
    int count=5;
    for (int i=0;i<count;i++)
    {
        node *n=malloc(sizeof(node));
        if (n==NULL)
        {
            return 1;
        }
        n->number=i;
        n->next=list;
        list=n;
    }
    //reading through the list
    node *ptr=list;
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->number);
        ptr=ptr->next;
    }
}