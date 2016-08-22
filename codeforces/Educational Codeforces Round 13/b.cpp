#include<iostream>
#include<cstdio>
using namespace std;
int y,temp;
bool flag;
bool isleap(int y)
{
    if( (y%400==0) || (y%4==0 && y%100!=0) )
        return 1;
    return 0;
}
int main()
{
    while(~scanf("%d",&y))
    {
        temp=0;
        flag=false;
        if(isleap(y))
        {
            temp=2;
            flag=true;
        }
        else
        {
            temp=1;
        }
        while(!(temp==0&&(isleap(y+1)==flag)))
        {
            y++; 
            if(isleap(y))
            {
                temp+=2;
            }
            else
            {
                temp+=1;
            }
            temp=temp%7;
        }
        printf("%d\n",y+1);
    }
    return 0;
}
