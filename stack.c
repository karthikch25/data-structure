#include<stdio.h>
#include<stdlib.h>
//Stack
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
            head=newnode;
            return head;
        }
        else
        {
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=newnode;
            return head;
        }
}
void pop(stk * head)
{int x;
  stk *t=head;
stk *p=t;
if(head==NULL)
{
    return;
}
while(t->next!=NULL)
{
  p = t;
    t=t->next;
}
x=t->data;
p->next = NULL;
printf("%d",x);
free(t);
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
    case 2: pop(head);
            break;
    default:printf("enter valid number");
            break;
    }
    }
}
