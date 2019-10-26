#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[]={1,1,1,1,-1,-1,-1,-1,2,2,2,3,3,4,4,4,4,6,6,6};

int generate()
{
    return rand() % (20 - 0 + 1);
}

void input(int index[])
{
    int i;
    system("clear");
    for (i=0;i<8;i++) 
    {
        if(a[index[i]]!=-1)
        printf("%d\t",a[index[i]]);
        else
        printf("\033[1;31mW\t\033[0m");
    }
    printf("\n");
}

void delay()
{
    clock_t time;
    time=clock()+300000;
    while(clock()<time);
}

int main()
{
    int over=0,runs,i=0,flag=1,temp,index[8],j; 
    char *c;
    clock_t del;
    srand(time(0));
    while(over<=12)
    {
        for(j=0;j<8;j++)
        index[j]=generate();
        do
        {
            input(index);
            temp=i;
            while(temp--)
            printf("\t");
            printf("|");
            fflush(stdout);
            printf("\r");
            delay();
            if(flag)
            {
                i++;
                if(i==7)
                flag=0;
            }
            else
            {
                i--;
                if(i==0)
                flag=1;
            }
        }while(1);
    }
    return 0;
}