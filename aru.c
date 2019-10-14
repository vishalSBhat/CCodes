#include<stdio.h>
int main()
{
    char a[5];
    int i,j,k,m,n;
    i=j=k=0;
    printf("\nEnter your 5 letter word\n");
    scanf("%s",a);
    while(i<5)
    {
        j=0;
            int x[4],b=0;
            while(b<4)
            {
                if(!(j==i)){
                x[b]=j;
                b++;
                }
                j++;
            }
        j=0;
        while(j<4)
        {
            k=0;
            m=x[j];
            b=0;
            int y[3],c=0;
                while(c<3)
                {
                    if(b!=i && b!=x[j]){
                    y[c]=b;
                    c++;
                    }
                    b++;
                }
            k=0;
            while(k<3)
            {
                n=y[k];
                printf("%c%c%c\n",a[i],a[m],a[n]);
                k++;
            }
            j++;
        }
        i++;
    }
    return 0;
}