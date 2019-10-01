#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *lp;
    int x;
    struct node *rp;
}node;
node * getNode()
{
    return (node *)malloc(sizeof(node));
}
node * insert(node *p)
{
    node *i=p;
    node *curr=getNode();
    curr->lp=NULL;
    curr->rp=NULL;
    printf("\nEnter value\n");
    scanf("%d",&curr->x);
    if(p==NULL)
    p=curr;
    else if(curr->x<i->x)
    {
        curr->rp=p;
        p->lp=curr;
        p=curr;
    }
    else
    {
        while(i->rp!=NULL && curr->x>i->rp->x)
        i=i->rp;
        curr->lp=i;
        curr->rp=i->rp;
        if(i->rp!=NULL)
        i->rp->lp=curr;
        i->rp=curr;
    }
    return p;
}
node * delete(node *p)
{
    if(p==NULL)
    printf("\nQ Empty\n");
    else{
    node *temp=p;
    p=p->rp;
    free(temp);
    if(p!=NULL)
    p->lp=NULL;
    }
    return p;
}
void show(node *f)
{
    if(f==NULL)
    printf("\nQ Empty\n");
    else{
    node *i;
    i=f;
    printf("\nElements in Q:\n");
    while(i)
    {
        printf("%d\n",i->x);
        i=i->rp;
    }
}
}
int main()
{
    node *r=NULL,*f=NULL;
    int ch;
    do
    {
        printf("\n1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.SHOW\n");
        printf("4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            f=insert(f);
            break;
            case 2:
            f=delete(f);
            break;
            case 3:
            show(f);
            break;
        }
    } while (ch!=4);
    return 0;
}