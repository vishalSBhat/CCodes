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
        curr->link=r;
        r=curr;
    }
    printf("\nEnter value\n");
    scanf("%d",&r->x);    
    return r;
}
node * delete(node *r)
{
    if(r==NULL)
    printf("\nQ Empty\n");
    else{
    node *i,*j;
    int c=0;
    i=r;
    while(i->link)
    {
        c++;
        j=i;
        i=i->link;
    }
    free(i);
    if(c!=0)
    j->link=NULL;
    else
    r=NULL;
    }
    return r;
}
void show(node *r)
{
    if(r==NULL)
    printf("\nQ Empty\n");
    else{
    node *i;
    i=r;
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
    node *r=NULL;
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
            break;
            case 2:
            r=delete(r);
            break;
            case 3:
            show(r);
            break;
        }
    } while (ch!=4);
    return 0;
}