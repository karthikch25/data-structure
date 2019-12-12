#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}dll;
dll* head=NULL;
dll * insertnode(dll* head,int data,int position){
    dll *t=head;
    dll* newnode=(dll*)malloc(sizeof(dll));
    newnode->data=data;
    newnode->prev=NULL;
    if(position==1||head==NULL)
    {   
        if(position==1&&head==NULL)
        {
            newnode->next=NULL;
            newnode->prev=NULL;
            head=newnode;
            return head;
        }
        head->prev=newnode;
        newnode->prev=NULL;
        newnode->next=head;
        head=newnode;
        return head;
    }
    for(int i=1;i<position-1;i++)
    {
        t=t->next;
    }
     if(t->next==NULL)
        {
            newnode->next=NULL;
            newnode->prev=t;
            t->next=newnode;
            return head;
        }
    newnode->next=t->next;
    newnode->prev=t;
    t->next->prev=newnode;
    t->next=newnode;
    return head;
}
void delete(dll* head ,int position)
{dll* t=head;
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
    t->next->prev=t;
}
void print(dll* head)
{dll *t=head;
    while(t!=NULL)
    {
        printf("%d->",t->data);
        t=t->next;
    }printf("NULL\n");
}
int main()
{   int val,pos,n;
    dll* head=NULL;
    dll* temp;
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
            head = insertnode(head,val,pos);
            print(head);
            break;
    case 2: printf("enter the position of the deleting node:");
            scanf("%d",&pos);
            delete(head,pos);
            print(head);
            break;
    default: printf("enter valid number\n");
            break;
    }
    }
}
