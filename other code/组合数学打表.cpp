#include<iostream>
#define ll long long
using namespace std;
#define maxm 
#define maxn
ll c[maxm][maxn];
void play_table()
{
    for(int i=0;i<=maxm;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j||i==j)
            {
                c[i][j]=1;
            }
            else
            {
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
    return;
}

int main()
{
	play_table(); 
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<6;j++)
		{
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
} 

#include <iostream>  
#include <string.h>  
using namespace std;  
  
int c[11][11];  
  
void init()  
{  
    memset(c,0,sizeof(c));  
    c[0][0]=c[1][0]=c[1][1]=1;  
    for(int i=2;i<=10;i++)  
    {  
        c[i][0]=c[i][i]=1;  
        for(int j=1;j<i;j++)  
            c[i][j]=c[i-1][j]+c[i-1][j-1];  
    }  
}  
  