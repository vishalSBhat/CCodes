#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int x;
    struct tree *lp;
    struct tree *rp;
}tree;
tree * getTree()
{
    return (tree *)malloc(sizeof(tree));
}
tree * insert(tree *r)
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
void preshow(tree *r)
{
    if(r==NULL)
    return;
    printf("%d ",r->x);
    preshow(r->lp);
    preshow(r->rp);
}
void inshow(tree *r)
{
    if(r==NULL)
    return;
    inshow(r->lp);
    printf("%d ",r->x);
    inshow(r->rp);
}
void postshow(tree *r)
{
    if(r==NULL)
    return;
    postshow(r->lp);
    postshow(r->rp);
    printf("%d ",r->x);
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
            r=insert(r);
            break;
            case 2:
            preshow(r);
            printf("\n");
            inshow(r);
            printf("\n");
            postshow(r);
        }
    } while (ch!=3);
    return 0;
}