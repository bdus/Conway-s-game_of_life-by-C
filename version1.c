#include<stdio.h>
#include<stdlib.h>

#define volume_m 35
#define volume_n 35
#define BreakCircle 20

    //i[m][n] m 列 n行
    //cols是说有几列，rows是说有几行

void Draw(int *p,int m,int n);
void DataRefresh(int *p,int *q,int m ,int n);
int StatusNext(int *p,int m,int n,int i,int j);
void Genesis(int *p,short,short);

int main(void)
{
    int orgData[volume_m][volume_n] = {0};
    int resData[volume_m][volume_n] = {0};

    short Circle = 0;
    short LiveOrNot = 1;

    system("echo WSCript.sleep 1000>%temp%\\bdustemsleep.vbs");

    Genesis(&orgData[0][0],volume_m,volume_n);

    while(LiveOrNot)
    {

//orgData to resData
        Circle++;
        system("cls");

        Draw(&orgData[0][0],volume_m,volume_n);
        system("start /wait %temp%\\bdustemsleep.vbs");

        DataRefresh(&orgData[0][0],&resData[0][0],volume_m,volume_n);

//resData to orgData
        Circle++;
        system("cls");

        Draw(&resData[0][0],volume_m,volume_n);
        system("start /wait %temp%\\bdustemsleep.vbs");

        DataRefresh(&resData[0][0],&orgData[0][0],volume_m,volume_n);
//Break
        if(Circle>=BreakCircle)
        {
            Circle = 0;
            LiveOrNot = 0;
        }
    }

    system("pause");
    system("del %temp%\\bdustemsleep.vbs&&exit");

    return 0;
}

void Genesis(int *p, short cols, short rows )
{
    //cols(n)是说有几列，rows(m)是说有几行
    int i,j;
    int orgArray[volume_m][volume_n] = {

//0      5        10        15        20        25        30
{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },//0
{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },//1
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//2
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//3
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//4
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//5
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//6
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//7
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//8
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//9

{0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//10
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//1
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//2
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//3
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//4
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//5
{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//6
{0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//7
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//8
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//9

{0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//20
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//1
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },//2
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0 },//3
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0 },//4
{0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0 },//5
{0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//6
{0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//7
{0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//8
{0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//9

{0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },//30
{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },//
{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },//
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0 },//

    };

    for(i=0; i<cols; i++)
    {
        for(j=0; j<rows; j++)
        {
            *(p+i*cols+j) = orgArray[i][j];
        }
    }

}
int StatusNext(int *p,int m,int n,int i,int j)//initial
{

    int ans;

    int sum = 0;
     sum =
        *(p+((i-1+m)%m)*n+(j+1)%n) + *(p+((i-1+m)%m)*n+j) + *(p+((i-1+m)%m)*n+(j+1)%n) +

        *(p+i*n+(j-1+n)%n)  +         /* *(p+i*n+j),  */      *(p+i*n+(j+1)%n)  +

        *(p+((i+1)%m)*n+(j-1+n)%n) + *(p+((i+1)%m)*n+j)  +  *(p+((i+1)%m)*n+(j+1)%n)
    ;


    if(*(p+n*i+j) == 0)
    {
        if(sum==3)
            ans = 1;
        else
            ans = 0;
    }

    else if(*(p+n*i+j) == 1)
    {
        if((sum<2)||(sum>3))
            ans = 0;
        else if((sum == 2)||(sum==3))
            ans = 1;
        else
            ;

    }

    return ans;
}

void DataRefresh(int *p,int *q,int m ,int n)
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            *(q+i*n+j) = StatusNext(p+i*n+j,m,n,i,j);
            // resData = f(orgData)
        }
    }
}


void Draw(int *p,int m,int n)
{
    int i,j;
    for( i=0; i<m; i++)
    {
        for( j=0; j<n; j++ )
        {
            if(*(p+i*n+j) == 0)
                printf(".");
            else if(*(p+i*n+j) == 1)
                printf("o");
        }
        printf("|\n");
    }
}
