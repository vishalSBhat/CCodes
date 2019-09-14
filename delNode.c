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
node * insert(node *h)
{
    node *curr=getNode();
    curr->link=NULL;
    if(h==NULL)
    h=curr;
    else
    {
        node *i=h;
        while(i->link)
        i=i->link;
        i->link=curr;
    }
    printf("\nEnter value\n");
    scanf("%d",&curr->x);    
    return h;
}
node * delete(node *h)
{
    node *temp=h,*temp1=NULL;
    int c=1,n;
    if(h==NULL)
    printf("\nList Empty\n");
    else
    {
        printf("\nWhich node do you want to delete??\n");
        scanf("%d",&n);
        while((c!=n) && (temp->link!=NULL))
        {
            c++;
            temp1=temp;
            temp=temp->link;
        }
        if(c==n){
            if(n==1)
            {
                h=h->link;
                free(temp);
            }
            else
            {
                temp1->link=temp->link;
                free(temp);
            }
        }
        else
        printf("No node found\n");
    }
    return h;
}
void show(node *h)
{
    if(h==NULL)
    printf("\nList Empty\n");
    else{
    node *i;
    i=h;
    printf("\nElements in List:\n");
    while(i)
    {
        printf("%d\n",i->x);
        i=i->link;
    }
    }
}
int main()
{
    node *h=NULL;
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
            h=insert(h);
            break;
            case 2:
            h=delete(h);
            break;
            case 3:
            show(h);
            break;
        }
    } while (ch!=4);
    return 0;
}