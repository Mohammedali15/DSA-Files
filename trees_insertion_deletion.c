#include <stdio.h>
#include <stdlib.h>

struct branch
{
    int data;
    struct branch *llink;
    struct branch *rlink;
};

typedef struct branch *BRANCH;

BRANCH create(int k);
BRANCH insert(BRANCH root, int k);
BRANCH deleteelement(BRANCH root,int m);
void inorder(BRANCH root);
int main()
{
    BRANCH root = NULL;
    int n,m;
    printf("Enter the number of nodes in the tree\n");
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        root = insert(root, a[i]);
    }
    printf("Enter the element that you want to delete\n");
    scanf("%d",&m);
    root=deleteelement(root,m);
    inorder(root);
    return 0;
}

BRANCH create(int k)
{
    BRANCH newnode;
    newnode = malloc(sizeof(struct branch));
    newnode->data = k;
    newnode->llink = NULL;
    newnode->rlink = NULL;
    return newnode;
}

BRANCH insert(BRANCH root, int k)
{
    BRANCH tp, newnode;
    if (root == NULL)
    {
        newnode = create(k);
        newnode->data = k;
        return newnode;
    }
    else
    {
        if (k >= root->data)
        {
            root->rlink = insert(root->rlink, k);
        }
        else
        {
            root->llink = insert(root->llink, k);
        }
    }
    return root;
}
BRANCH deleteelement(BRANCH root,int key)
{
    if(root==NULL)
    {
        printf("key not found\n");
    }
    else if(root->data==key)
        {
            if(root->llink==NULL && root->rlink==NULL)
            {
                printf("%d is deleted\n",root->data);
                free(root);
                return NULL;
            }
            else if(root->llink==NULL && root->rlink!=NULL)
            {
                BRANCH temp = root->rlink;
                printf("%d is deleted\n",root->data);
                free(root);
                return temp;
            }
            else if(root->llink!=NULL && root->rlink==NULL)
            {
                BRANCH temp = root->llink;
                printf("%d is deleted\n",root->data);
                free(root);
                 return temp;
            }
            else if(root->llink!=NULL && root->rlink!=NULL)
            {
                 BRANCH cur=root,prev=root ;
                 cur=cur->llink;
                 while(cur->rlink!=NULL)
                 {
                     prev=cur;
                    cur=cur->rlink;
                 }
                 if(cur==root->llink)
                 {
                     root->data=cur->data;
                     root->rlink=cur->rlink;
                     free(cur);
                 }
                 else
                {
                    root->data=cur->data;
                    prev->rlink=cur->llink;
                    free(cur);
                 }
                 return root;
            }
        }
         else if(key>root->data)
            {
                root->rlink=deleteelement(root->rlink,key);
            }

        else{
                root->llink=deleteelement(root->llink,key);
        }

    return root;
}


void inorder(BRANCH root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%d ", root->data);
        inorder(root->rlink);
    }
}
