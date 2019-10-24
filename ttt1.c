#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
int a[3][3]; 
void display()
{
    system("clear");
        int i,j;
        for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        if(a[i][j]==1) 
                        printf(" X "); 
                        else if(a[i][j]==0) 
                        printf(" O "); 
                        else 
                        printf(" %d ",a[i][j]-10); 
                        if(j==0 || j==1)
                        printf("|"); 
                }
                printf("\n");
                if(i==0 || i==1)
                printf("-----------");
                printf("\n");
        }
}
int input(int f,int ot[],int b,int z) 
{ 
        int count=0; 
        while(f-->=0) 
        if(ot[f]==b) 
        count++; 
        if(count>=1){
        printf("Already chosen\n");         
        return 10;
        }
        switch(b) 
        { 
        case 1: 
        a[0][0]=z; 
        break; 
        case 2: 
        a[0][1]=z; 
        break; 
        case 3: 
        a[0][2]=z; 
        break; 
        case 4: 
        a[1][0]=z; 
        break; 
        case 5: 
        a[1][1]=z;
        break; 
        case 6: 
        a[1][2]=z; 
        break; 
        case 7: 
        a[2][0]=z; 
        break; 
        case 8: 
        a[2][1]=z; 
        break; 
        case 9: 
        a[2][2]=z; 
        break; 
        default: 
        printf("Select a proper place!!\n"); 
        } 
        return b; 
} 
int check(int sum)
{
        if(sum==3 || sum==0)
        return 1;
        else
        return 0;
}
int condition(int i,int j) 
{ 
    display();    
    if(a[i][j]==1) 
    printf("Player 1 wins!!\n"); 
    else if(a[i][j]==0) 
    printf("Player 2 wins!!\n"); 
    return 0; 
} 
int main() 
{ 
    int ot[10],i,j,b=1,f=0; 
    clock_t wtime;
    for(i=0;i<3;i++) 
    for(j=0;j<3;j++) 
    a[i][j]=++f+10; 
    f=0;
    printf("\nPlayer 1 is X\nPlayer 2 is O\n\n");
    wtime=clock()+2000000;
    while(clock()<wtime);
    do 
    {
        display();      
        switch(b) 
        { 
            case 1: 
            printf("Player 1 choice..Choose your place of input\n"); 
            scanf("%d",&b);
            if(input(f,ot,b,1)!=10)
            { 
                ot[f]=b;
                b=2; 
                f++;
            } 
            else
            b=1;
            break; 
            case 2: 
            printf("PLayer 2 choice..Choose your place of input\n"); 
            scanf("%d",&b); 
            if(input(f,ot,b,0)!=10)
            { 
                ot[f]=b;
                b=1;
                f++;
            } 
            else
            b=2; 
        }
        if(f==9) 
        { 
        display();
        printf("Nobody Wins\n"); 
        break;
        }
        if(f>=5) 
        { 
        if(check(a[0][0]+a[0][1]+a[0][2])) 
        b=condition(0,0); 
        else if(check(a[1][0]+a[1][1]+a[1][2]))
        b=condition(1,0);
        else if(check(a[2][0]+a[2][1]+a[2][2])) 
        b=condition(2,0);
        else if(check(a[0][0]+a[1][0]+a[2][0])) 
        b=condition(0,0);
        else if(check(a[0][1]+a[1][1]+a[2][1]))  
        b=condition(0,1);
        else if(check(a[0][2]+a[1][2]+a[2][2]))  
        b=condition(0,2);
        else if(check(a[0][0]+a[1][1]+a[2][2])) 
        b=condition(0,0);
        else if(check(a[0][2]+a[1][1]+a[2][0]))  
        b=condition(0,2);
        }
    }while(b!=0); 
    return 0; 
} 
