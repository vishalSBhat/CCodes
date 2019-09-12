#include <stdio.h>
#include <math.h>
#include <ctype.h>
int push(int tos,int s[],int c)
{
    tos++;
    s[tos]=c;
    return tos;
}
int pop(int tos,int s[],char c)
{
    int a,b;
    b=s[tos];
    tos--;
    a=s[tos];
    tos--;
    switch(c)
    {
        case '+':
        tos=push(tos,s,(a+b));
        break;
        case '-':
        tos=push(tos,s,(a-b));
        break;
        case '*':
        tos=push(tos,s,(a*b));
        break;
        case '/':
        tos=push(tos,s,(a/b));
        break;
        case '$':
        tos=push(tos,s,(pow(a,b)));
        break;
    }  
    return tos;
}
void show(int s[])
{
    printf("\n%d\n",s[0]);
}
int main()
{
    int s[20];
    int tos=-1;
    char c;
    printf("enter\n");
    while((c=getchar())!='\n')
    {
        if(isdigit(c))
        tos=push(tos,s,c-48);
        else
        tos=pop(tos,s,c);
    }
    show(s);
    return 0;
}