#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int data;
    struct stck *next;
}stk;
stk* head=NULL;
stk * push(stk *head,int data)
{
    stk *t=head;
    stk *newnode=(stk *)malloc(sizeof(stk));
    newnode->data=data;
    newnode->next=NULL;
        if(head==NULL)
        {
            t=newnode;
            return t;
        }
        else
        {
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=newnode;
            return newnode;
        }
}
stk * pop(stk * head)
{stk *t=head;
stk *p;
if(head==NULL)
{
    return NULL;
}
while(t->next!=NULL)
{
    t=t->next;
}
p=t;
return p;
}
int main()
{   int ch,val;
    stk* head=NULL;
    stk* temp;
    while(1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("enter your choice:");
        scanf("%d",&ch);
    switch(ch)
    {
     case 1: printf("enter data:");
            scanf("%d",&val);
            head = push(head,val);
            printf("%d\n",head->data);
            break;
    case 2: head=pop(head);
            printf("%d\n",head->data);
            break;
    default:printf("enter valid number");
            break;
    }
    }
}
