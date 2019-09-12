#include<stdio.h>
#include<stdlib.h>

int insert(int r,int *q,int x)
{
    r++;
    *(q+r)=x;
    return r;
}
int delete(int f,int *q)
{
    f++;
    return f;
}
void display(int f,int r,int *q)
{
    int i;
    printf("\nElements in Q :\n");
    for(i=f;i<=r;i++)
    printf("\n%d",*(q+i));
    printf("\n");
}


int main()
{
    int f,r,*q,x,n,ch;
    char err;
    f=r=-1;
    printf("Enter length of your Q\n");
    scanf("%d",&n);
    q=(int *)malloc(n*sizeof(int));
    do
    {
        printf("\n");
        printf("1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.SHOW\n");
        printf("4.EXIT\n");
        printf("\n");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1:
            if(r+1==n)
            printf("Q full\n");
            else
            {
                if(r==-1)
                f=0;
                printf("Enter value to be inserted\n");
                scanf("%d",&x);
                r=insert(r,q,x);
                display(f,r,q);
            }
            break;
            case 2:
            if(f==-1)
            printf("Q Empty\n");
            else
            {
                f=delete(f,q);
                display(f,r,q);
            }
            break;
            case 3:
            if(r==-1)
            printf("Q Empty\n");
            else
            display(f,r,q);
            break;
            case 4:
            ch=0;
            break;
        }
        if(f>r)
        f=r=-1;
    }while (ch!=0);
    
}