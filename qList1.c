#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int x;
    struct node *link;
}node;
node * getNode()
{
    return (node *)malloc(sizeof(node));
}
node * insert(node *r)
{
    node *curr=getNode();
    curr->link=NULL;
    if(r==NULL)
    r=curr;
    else
    {
        r->link=curr;
        r=curr;
    }
    printf("\nEnter value\n");
    scanf("%d",&r->x);    
    return r;
}
node * delete(node *f)
{
    if(f==NULL)
    printf("\nQ Empty\n");
    else{
    node *temp=f;
    f=f->link;
    free(temp);
    }
    return f;
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
        i=i->link;
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
            r=insert(r);
            if(f==NULL)
            f=r;
            break;
            case 2:
            f=delete(f);
            if(f==NULL)
            r=NULL;
            break;
            case 3:
            show(f);
            break;
        }
    } while (ch!=4);
    return 0;
}
