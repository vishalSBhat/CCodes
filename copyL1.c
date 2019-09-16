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
node * createList(node *h1,node *h)
{
    node *curr,*temp=h;
    if(!temp)
    return h1;
    else
    {
        curr=getNode();
        curr->link=NULL;
        curr->x=temp->x;
        if(h1==NULL)
        h1=curr;
        else
        {
            curr->link=h1;
            h1=curr;
        }
        return createList(h1,temp->link);
    }
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
void del(node *h1)
{
    node *i;
    while(h1!=NULL)
    {
        i=h1;
        h1=h1->link;
        free(i);
    }
}
int main()
{
    node *h=NULL,*h1=NULL;
    int ch,flag=0,n;
    do
    {
        printf("\n1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.SHOW\n");
        printf("4.CREATE NEW LIST??\n");
        printf("5.EXIT\n");
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
            printf("Which List??\n");
            scanf("%d",&n);
            if(n==1)
            show(h);
            else
            {
                if(flag==0)
                printf("No List created\n");
                else
                show(h1);
            }
            break;
            case 4:
            flag=1;
            del(h1);
            h1=NULL;
            h1=createList(h1,h);
            break;
        }
    } while (ch!=5);
    return 0;
}