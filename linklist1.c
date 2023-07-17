#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct node *next;
};
typedef struct Node *node;
node head,newnode,temp,cur,temp1,temp2;
node insert(node,int choice);
void display(node head,int choice);
node getnode();
node read_details(node newnode,int choice);
node head=NULL;
 main()
{
int choice;
while(1)
{
    printf("1-->insert\n2-->arrange\n");
        printf("\nenter choice:\n");
        scanf("%d",&choice);
    switch(choice)
        {
        case 1: head=insert(newnode,choice);break;
        case 2: display(head,choice);  break;
        }
}
 }
node getnode()
{
 newnode=(node)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
return newnode;
}
node read_details(node newnode,int choice)
{
    if(choice==1)
    {

    printf("enter data\n");
    scanf("%d",&newnode->data);
     newnode->next=NULL;
    return newnode;
    }
}
node insert(node newnode,int choice)
{
    newnode=getnode();
    if(choice==1)
    {
    newnode=read_details(newnode,choice);
    }
    if(head==NULL)
    {
        head=newnode;
        return(head);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        return(head);
    }
}
void display(node head,int choice)
{
    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data<0)
        {
            newnode=getnode();
            temp1=newnode;
            temp1->data=temp->data;
            temp1->next=NULL;
            temp1=insert(temp1,choice);
        }
        else if(temp->data>0)
        {
            newnode=getnode();
            temp2=newnode;
            temp2->data=temp->data;
            temp2->next=NULL;
            temp2=insert(temp2,choice);
        }
    }
    printf(" list of positive numbers is:\n");
        while(temp1!=NULL)
        {
            printf("%d->",temp1->data);
            temp1=temp1->next;
        }
        printf("\n");
    printf(" list of negative numbers is:\n");
        while(temp2!=NULL)
        {
            printf("%d->",temp2->data);
            temp2=temp2->next;
        }
        printf("\n");
}
