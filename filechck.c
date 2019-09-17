#include<stdio.h>
#include<ctype.h>

int main()
{
    FILE *p;
    int x=0,y=0;
    char c;
    p=fopen("copyL1.c","r");
    while((c=fgetc(p))!=EOF)
    {
        if(c=='{')
        x++;
        else if(c=='}')
        y++;
    }
    if(x==y)
    printf("\nCorrect\n");
    else
    printf("\nNo matching pairs\n");
    return 0;

}