#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
char a[100];
int i=0;
int push(int tos,char *s,char c)
{
    tos++;
    *(s+tos)=c;
    return tos;
}
int pop(int tos,char *s)
{
    a[i]=*(s+tos);
    i++;
    tos--;
    return tos;
}
int check(char c)
{
    switch(c)
    {
        case '(':
        return 0;
        break;
        case '-':
        return 1;
        break;
        case '+':
        return 2;
        break;
        case '*':
        return 3;
        break;
        case '/':
        return 4;
        break;
        case '$':
        return 5;
        break;
    }
    return 0;
}
int main()
{
    char *s,c,err;
    int tos=-1,x=0,n;
    printf("Enter size of expression\n");
    scanf("%d",&n);
    scanf("%c",&err);
    s=(char *)malloc(n*sizeof(char));
    printf("\nEnter your expression\n");
    while((c=getchar())!='\n')
    {
        if(isalpha(c))
        {
            a[i]=c;
            i++;
        }
        else if(c=='(')
        tos=push(tos,s,c);
        else if(c==')'){
        while(s[tos]!='(')
        {
            tos=pop(tos,s);
        }
        tos--;
        }
        else
        {
            if(tos==-1)
            tos=push(tos,s,c);
            else
            {
                int x,y;
                x=check(c);
                y=check(s[tos]);
                if(x>=y)
                tos=push(tos,s,c);
                else
                {
                    while(*(s+tos)!='(')
                    {
                        if(tos!=-1)
                        tos=pop(tos,s);
                        else
                        break;
                    }
                    tos=push(tos,s,c);
                }
            }
            
        }
    }
    while(tos!=-1)
    {
        tos=pop(tos,s);
    }
    printf("\n%s\n",a);
    return 0;
}