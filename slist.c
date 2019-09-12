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
node * push(node *tos)
{
    node *curr=getNode();
    curr->link=NULL;
    if(tos==NULL)
    tos=curr;
    else
    {
        curr->link=tos;
        tos=curr;
    }
    printf("\nEnter value\n");
    scanf("%d",&tos->x);    
    return tos;
}
node * pop(node *tos)
{
    node *temp;
    if(tos==NULL)
    printf("\nStack Underflow\n");
    else
    {
        temp=tos;
        tos=tos->link;
        free(temp);
    }
    return tos;
}
void show(node *tos)
{
    if(tos==NULL)
    printf("\nStack Empty\n");
    else{
    node *i;
    i=tos;
    printf("\nElements in Stack:\n");
    while(i)
    {
        printf("%d\n",i->x);
        i=i->link;
    }
    }
}
int main()
{
    node *tos=NULL;
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
            tos=push(tos);
            break;
            case 2:
            tos=pop(tos);
            break;
            case 3:
            show(tos);
            break;
        }
    } while (ch!=4);
    return 0;
}