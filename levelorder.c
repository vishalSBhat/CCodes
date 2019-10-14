#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    int x;
    struct tree *lp;
    struct tree *rp;
}tree;
typedef struct node
{
    tree *x;
    struct node *link;
}node;
node * getNode()
{
    return (node *)malloc(sizeof(node));
}
node * insert(node *r,tree *y)
{
    if(y==NULL)
    return r;
    if(r==NULL)
    {
        node *curr=getNode();
        curr->link=NULL;
        curr->x=y;
        r=curr;
    }
    else
    {
        r->link->link=NULL;
        r->link->x=y;
        r=r->link;
    }  
    node *temp=getNode();
    temp->x=NULL;
    temp->link=NULL;
    r->link=temp;
    return r;
}
tree * getTree()
{
    return (tree *)malloc(sizeof(tree));
}
tree * Insert(tree *r)
{
    tree *curr=getTree();
    curr->lp=curr->rp=NULL;
    printf("\nEnter element to be inserted\n");
    scanf("%d",&curr->x);
    if(r==NULL)
    {
        r=curr;
        return r;
    }
    tree *temp=r,*i;
    int c=0;
    while(temp!=NULL)
    {
        i=temp;
        if(temp->x > curr->x)
        {
            temp=temp->lp;
            c=0;
        }
        else
        {
            temp=temp->rp;
            c=1;
        }
    }
    if(c==0)
    i->lp=curr;
    else
    i->rp=curr;
    return r;
}
void show(tree *r)
{
    node *re,*f,*t;
    re=f=NULL;
    tree *temp=r;
    while(temp!=NULL)
    {
        printf("%d  ",temp->x);
        re=insert(re,temp->lp);
        if(f==NULL)
        f=re;
        re=insert(re,temp->rp);
        if(f==NULL)
        f=re;
        temp=f->x;
        f=f->link;
    }
}
int main()
{
    int ch;
    tree *r=NULL;
    do
    {
        printf("\n1.INSERT\n");
        printf("2.SHOW\n");
        printf("3.EXIt\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            r=Insert(r);
            break;
            case 2:
            if(r->lp==NULL && r->rp==NULL)
            printf("%d\n",r->x);
            else
            show(r);
        }
    } while (ch!=3);
    return 0;
}