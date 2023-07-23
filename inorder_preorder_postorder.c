#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
    int height;
};
typedef struct node *NODE;
NODE create_node(int key);
NODE insert(NODE root,int key);
NODE deletion(NODE root,int key);
NODE left_rotate(NODE root);
NODE right_rotate(NODE root);
int height(NODE root);
int balanace_factor(NODE root);
void preorder(NODE root);
void inorder(NODE root);
void postorder(NODE root);
int max(int a,int b);
int main()
{
    NODE root=NULL;
    int m,n;
    while(1)
    {
        printf("1:Insertion 2:deletion 3:preorder 4:inorder 5:postorder 6:exit\n");
        scanf("%d",&m);
        if(m==1)
        {
            printf("Enter the element\n");
            scanf("%d",&n);
            root=insertion(root,n);
        }
        else if(m==2)
        {
            printf("Enter the element that you want to delete\n");
            scanf("%d",&n);
            root=deletion(root,n);
        }
        else if(m==3)
        {
            preorder(root);
        }
        else if(m==4)
        {
            inorder(root);
        }
        else if(m==5)
        {
            postorder(root);
        }
        else if(m==6)
        {
            exit(0);
        }
    }
}
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int height(NODE root)
{
    if(root==NULL)
        return 0;
    else
         return root->height;
}
int balanace_factor(NODE root)
{
    if(root==NULL)
        return 0;
    else
        return (height(root->llink)-height(root->rlink));
}
NODE create_node(int key)
{
    NODE newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->rlink=newnode->link=NULL;
    newnode->height=1;
    return newnode;
}
NODE left_rotate(NODE root)
{
    NODE a,b;
    a=root->rlink;
    b=a->llink;

    a->llink=root;
    root->llink=b;
}
NODE insertion(NODE root,int key);
{
    int bl;
    NODE newnode;
    if(root==NULL)
    {
        newnode=create_node(key);
        return newnode;
    }
    else
    {
        if(key>=root->data)
        {
            root->rlink=insertion(root->rlink,key);
        }
        else
        {
            root->link=insertion(root->llink,key);
        }
    }
    root->height=1+max(height(root->llink),height(root->rllink));
    bl=height(root->llink)-height(root->rlnk);
    if(bl<-1 && key>)
    {

    }
}
