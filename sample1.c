#include "stdafx.h"
#include <fstream.h>
#include <stdlib.h>

#define WLIFE 80
#define HLIFE 20

void gentions(char LIFE[][WLIFE])
{
    int high,weith;
    int s;
    char LIF[HLIFE][WLIFE];
    for(high=0; high<HLIFE; high++)
        {
            for(weith=0; weith<WLIFE; weith++)
            {
                s=0;
                if(high==0)
                {
                    if(LIFE[high+1][weith]=='*') s++;
                    if(weith==0)
                    {
                        if(LIFE[high+1][weith+1]=='*') s++;
                        if(LIFE[high][weith+1]=='*') s++;
                    }
                    else if(weith==WLIFE-1)
                    {
                        if(LIFE[high+1][weith-1]=='*') s++;
                        if(LIFE[high][weith-1]=='*') s++;
                    }
                    else
                    {
                        if(LIFE[high+1][weith-1]=='*') s++;
                        if(LIFE[high][weith-1]=='*') s++;
                        if(LIFE[high+1][weith+1]=='*') s++;
                        if(LIFE[high][weith+1]=='*') s++;
                    }
                }
                else if(high==HLIFE-1)
                {
                    if(LIFE[high-1][weith]=='*') s++;
                    if(weith==0)
                    {
                        if(LIFE[high-1][weith+1]=='*') s++;
                        if(LIFE[high][weith+1]=='*') s++;
                    }
                    else if(weith==WLIFE-1)
                    {
                        if(LIFE[high-1][weith-1]=='*') s++;
                        if(LIFE[high][weith-1]=='*') s++;
                    }
                    else
                    {
                        if(LIFE[high-1][weith+1]=='*') s++;
                        if(LIFE[high][weith+1]=='*') s++;
                        if(LIFE[high-1][weith-1]=='*') s++;
                        if(LIFE[high][weith-1]=='*') s++;
                    }
                }
                else if(high!=0 && high!=HLIFE-1)
                {
                    if(LIFE[high-1][weith]=='*') s++;
                    if(LIFE[high+1][weith]=='*') s++;
                    if (weith==0)
                    {
                    if(LIFE[high-1][weith+1]=='*') s++;
                    if(LIFE[high][weith+1]=='*') s++;
                    if(LIFE[high+1][weith+1]=='*') s++;
                    }
                    else if(weith==WLIFE-1)
                    {
                    if(LIFE[high-1][weith-1]=='*') s++;
                    if(LIFE[high][weith-1]=='*') s++;
                    if(LIFE[high+1][weith-1]=='*') s++;
                    }
                    else
                    {
                    if(LIFE[high-1][weith-1]=='*') s++;
                    if(LIFE[high][weith-1]=='*') s++;
                    if(LIFE[high+1][weith-1]=='*') s++;
                    if(LIFE[high-1][weith+1]=='*') s++;
                    if(LIFE[high][weith+1]=='*') s++;
                    if(LIFE[high+1][weith+1]=='*') s++;
                    }
                }                
                if(s==3) LIF[high][weith]='*';
                else LIF[high][weith]=' ';
            }
        }

        for(high=0; high<HLIFE; high++)
        {
            for(weith=0; weith<WLIFE; weith++)
            {
                LIFE[high][weith]=LIF[high][weith];
            }
        }
}

int main(int argc, char* argv[])
{
    char LIFE[HLIFE][WLIFE];
    int high,weith;
    char c;
    ifstream in;
    in.open("Generations.dat");
    if(in.fail())
    {
        cout<<"Open the error!";
        exit(1);
    }

    for(high=0; high<HLIFE; high++)
    {
        for(weith=0; weith<WLIFE; weith++)
        {
            in.get(c);
            if(c == '*') LIFE[high][weith]=c;
            else LIFE[high][weith]=' ';
        }
    }

    do
    {
        system("cls");
        for(high=0; high<HLIFE; high++)
        {
            for(weith=0; weith<WLIFE; weith++)
            {
                cout<<LIFE[high][weith];
            }
        }        
        gentions(LIFE);
        cout<<"按回车键查看下一个世代!"<<endl;
        cin.get(c);
    }while (c=='\n');
    return 0;
}
