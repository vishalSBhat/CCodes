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
node * insert(node *p,int ch)
{
    node *curr=getNode();
    curr->lp=NULL;
    curr->rp=NULL;
    printf("\nEnter value\n");
    scanf("%d",&curr->x);
    switch(ch)
    {
        case 1:
        if(p==NULL)
        p=curr;
        else
        {
            p->lp=curr;
            curr->rp=p;
            p=curr;
        }
        break;
        case 2:
        if(p==NULL)
        p=curr;
        else
        {
            p->rp=curr;
            curr->lp=p;
            p=curr;
        }
        break;
    }
    return p;
}
node * delete(node *p,int ch)
{
    switch(ch)
    {
        case 1:
        if(p==NULL)
        printf("\nQ Empty\n");
        else{
        node *temp=p;
        //p->rp->lp=NULL;
        p=p->rp;
        free(temp);
        if(p!=NULL)
        p->lp=NULL;
        }
        break;
        case 2:
        if(p==NULL)
        printf("\nQ Empty\n");
        else{
        node *temp=p;
        //p->lp->rp=NULL;
        p=p->lp;
        free(temp);
        if(p!=NULL)
        p->rp=NULL;
        }
        break;
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
    int ch,ch1;
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
            printf("\nWhich side do you want to insert??\n");
            printf("1.LEFT\n");
            printf("2.RIGHT\n");
            scanf("%d",&ch1);
            if(ch1==1){
            f=insert(f,ch1);
            if(r==NULL)
            r=f;
            }
            else{
            r=insert(r,ch1);
            if(f==NULL)
            f=r;
            }
            break;

            case 2:
            printf("\nWhich side do you want to delete??\n");
            printf("LEFT\n");
            printf("RIGHT\n");
            scanf("%d",&ch1);
            if(ch1==1)
            {
                f=delete(f,ch1);
                if(f==NULL)
                r=NULL;
            }
            else
            {
                r=delete(r,ch1);
                if(r==NULL)
                f=NULL;
            }
            break;
            case 3:
            show(f);
            break;
        }
    } while (ch!=4);
    return 0;
}