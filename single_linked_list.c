#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}linkedlistnode;
linkedlistnode *head=NULL;
void insertnode(int data,int position)
{
    linkedlistnode * t=head;
    linkedlistnode * newnode=(linkedlistnode*)malloc(sizeof(linkedlistnode));
    newnode->data=data;
    newnode->next=NULL;
    if(position==1)
    {  newnode->next=head;
        head=newnode;
        return;
    }
        for(int i=1;i<position-1;i++)
        {
            t=t->next;
            
        }
         newnode->next=t->next;
                t->next=newnode;
}
void delete(int position)
{linkedlistnode* t=head;
    if(position==1)
    {
        head=head->next;
        return;
    }
   for(int i=1;i<position-1;i++)
        {
            t=t->next;
        }
    t->next=t->next->next;
}
void print()
{linkedlistnode *t=head;
    while(t!=NULL)
    {
        printf("%d->",t->data);
        t=t->next;
    }printf("NULL\n");
}
int main()
{   int val,pos,n;
    linkedlistnode* head=NULL;
    linkedlistnode* temp;
    while(1)
    {
        printf("1.insert at nth position\n");
        printf("2.delete at n position\n");
        printf("enter your choice:");
        scanf("%d",&n);
    switch(n)
    {
     case 1: printf("enter data:");
            scanf("%d",&val);
            printf("enter position:");
            scanf("%d",&pos);
            insertnode(val,pos);
            print();
            break;
    case 2: printf("enter the position of the deleting node:");
            scanf("%d",&pos);
            delete(pos);
            print();
            break;
    default: printf("enter valid number");
            break;
    }
    }
}
