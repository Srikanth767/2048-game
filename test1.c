#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
#define MAXRANDOMVALUE 3
#define MAXPREV 500
int arr[4][4]={0},c[4],temp=0,len=0,score=0,highscore=0,count=0,ch=0;//COUNT WILL COUNT THE NO OF STEPS
void print()
{
        int i,j,k,len1;
          printf("YOUR SCORE=%d\n",score);
          
              highscore=score;
//              printf("HIGH SCORE=",highscore);
          
    printf("---------------------------------\n");
    for (i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(j==0)
            {
                printf("|");
            }
            if(arr[i][j]!=0)
            {
                len1=findlen(arr[i][j]);
                //printf("%d:",len);

                for(k=0;k<4-len;k++)
                {
                    printf(" ");
                }
                printf("%d",arr[i][j]);

                for(k=0;k<4-len;k++)
                {
                    printf(" ");
                }
                for(k=0;k<len-1;k++)
                {
                    printf(" ");
                }
                printf("|");
            }
            else
            {
                for(k=0;k<8-2*len-1;k++){
                printf(" ");}printf("|");
            }
            len=0;
        }
        if(i!=3)
        {
        printf("\n");
    printf("---------------------------------\n");
        }

    }
//    printf("\n\t\t\t\t\t---------------------------------\n");
     printf("PREV-> P\n");
     printf("RESTART-> R\n");
     printf("EXIT-> U\n");
    printf("ENTER YOUR CHOISE -> W,S,A,D\n");

}
void movevalue(int k)
{
    int i;
    if(k==3 )
    {
        return;
    }
    for(i=k;i<4;i++)
    {
        if(c[i]!=0)
        {
            movevalue(i+1);
            for(;i<4;i++)
            {
                if(c[i+1]!=0)
                {
                    break;
                }
                    c[i+1]=c[i];
                    c[i]=0;
            }


        }
    }
}
int findlen(int n)
{

        if(n==0)
        {

            return len;
        }
        else
        {
            len++;
            findlen(n/10);
        }
}
void addrandomno()
{
    int no;
     srand(time(NULL));
    int i,j; //RANDOM INDEX
    do
    {
    i=(rand ())%(MAXRANDOMVALUE+1);
    j=(rand ())%(MAXRANDOMVALUE+1);
    }
    while(arr[i][j]!=0);
   //printf("%d %d",i,j);
    no=2*((rand ()%10)+1);
    if(no==3 || no==2)
    {
        arr[i][j]=4;
    }
    else
    {
        arr[i][j]=2;
    }
}
void rupdate()
{
    int i,j;
    for(i=3;i>0;i--)
    {
        if(c[i]==c[i-1] )
        {
            c[i]+=c[i-1];
            score=score+c[i];
            if(score>highscore)
            {

            }
            temp=1;
            c[i-1]=0;
        }
        else if(c[i-1]==0 && c[i]!=0 )
        {
            c[i-1]=c[i];
            c[i]=0;
            temp=1;
        }
        else if(c[i]==0)
        {
            temp=1;
        }
    }
        movevalue(0);

}
void createprev(int ***p)
{
      int i,j,k;

    if(count==MAXPREV+1)
    {
        for(i=MAXPREV;i>0;i--)
        {
            for(j=0;j<4;j++)
            {
                for(k=0;k<4;k++)
                {
                        p[i][j][k]=p[i-1][j][k];
                }
            }

        }
        count=MAXPREV;
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            p[MAXPREV-count][i][j]=arr[i][j];
        }

    }
}
void updatearrtoprev(int ***p)
{
    int data,i,j;
    if(count==0)
    {
        printf("\n\t\t\t\t\t******FURTHER MORE PREV NOT POSSIBLE********");
        return;
    }
        score=data;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            arr[i][j]=p[MAXPREV-count][i][j];
        }
    }
    count--;



}
void resetgame()
{
            int i,j;
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    arr[i][j]=0;

                }
            }
            system("cls") ;
            score=0;
            addrandomno();

}
int main()
{
    int i,j,k,m,n,same=0;
    char choise,s=-33,reschk;
   printf("2048\n");
    printf(" FOR MOVES:- 'W','S','A','D'");
    printf(" undo:- 'P'");
    printf("RESTAT THE GAME:- 'R'");
    printf("EXIT:-'U'");

    printf("PRESS ANY KEY TO START THE GAME..");

    getch();
    system("cls") ;
     printf("\n2048\n");
     
    sleep(1);
    system("cls") ;
    int ***p;
    p=(int ***)malloc(sizeof(int *)*(MAXPREV+1));
    for(i=0;i<MAXPREV+1;i++)
    {
        *(p+i)=(int **)malloc(sizeof(int *)*4);
    }
    for(i=0;i<MAXPREV+1;i++)
    {
        for( j=0;j<4;j++)
        {
            p[i][j]=(int *)malloc(sizeof(int)*4);
        }
    }
    createprev(p);

    addrandomno();
    print();
    while(1)
    {
        choise=getch();
        if(choise=='D' || choise =='d')
        {
            count++;ch++;
              createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    c[j]=arr[i][j];
                }
                    rupdate();
                for(k=0;k<4;k++)
                {
                    arr[i][k]=c[k];
                }
            }
        }
        else if(choise=='a' || choise=='A')
        {
            count++;
            ch++;
            createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    c[3-j]=arr[i][j];
                }
                rupdate();
                for(k=0;k<4;k++)
                {
                    arr[i][3-k]=c[k];
                }
            }
        }
        else if(choise=='s' || choise =='S')
        {
            count++;ch++;

               createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    c[j]=arr[j][i];
                }
                rupdate();
                for(k=0;k<4;k++)
                {
                    arr[k][i]=c[k];
                }
            }
        }
        else if(choise=='w' || choise=='W')
        {
            count++;ch++;

              createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    c[3-j]=arr[j][i];
                }
                rupdate();
                for(k=0;k<4;k++)
                {
                  arr[3-k][i]=c[k];
                }
            }
        }
        else if(choise=='p' || choise =='p')
        {

            updatearrtoprev(p);

            temp=8;
        }
        else if(choise=='R' || choise=='r')
        {
            count=0;
            resetgame();
            print();
            continue;
        }
        else if(choise=='u'||choise=='U')
        {
            exit(0);
        }

            if(temp==1)
            {
                temp=0;
                system("cls") ;
                printf("\n%c\n",choise);
                addrandomno();
                print();

            }
            else if(temp==8)
            {
                temp=0;
                print();
            }
            else
            {
                for(m=0;m<4;m++)
                {
                    for(n=3;n>0;n--)
                    {
                        if(arr[m][n]==arr[m][n-1] || arr[m][n]==0 || arr[m][n-1]==0)
                        {
                                same=1;
                                break;
                        }
                        if(arr[n][m]==arr[n-1][m] || arr[m][n]==0 || arr[m][n-1]==0)
                        {
                            same=1;
                            break;
                        }
                    }
                    if(same==1)
                        break;
                }
               if(same==1)
                {
                    printf("\nINVALID KEY");
                    same=0;


                }
                else
                {
                    printf("\nGAME OVER");
                    exit(3);

                }
            }
    }
    return 0;
}

