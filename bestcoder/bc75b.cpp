#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int t,k;
int a[15];
bool b[10][10];
bool c[10];
int main()
{
	b[1][4]=true;
	b[1][2]=true;
	b[1][5]=true;
	b[2][1]=true;
	b[2][4]=true;
	b[2][5]=true;
	b[2][6]=true;
	b[2][3]=true;
	b[3][2]=true;
	b[3][5]=true;
	b[3][6]=true;
	b[4][1]=true;
	b[4][2]=true;
	b[4][5]=true;
	b[4][8]=true;
	b[4][7]=true;
	b[5][1]=true;
	b[5][2]=true;
	b[5][3]=true;
	b[5][4]=true;
	b[5][6]=true;
	b[5][7]=true;
	b[5][8]=true;
	b[5][9]=true;
	b[6][3]=true;
	b[6][2]=true;
	b[6][5]=true;
	b[6][8]=true;
	b[6][9]=true;
	b[7][4]=true;
	b[7][5]=true;
	b[7][8]=true;
	b[8][7]=true;
	b[8][4]=true;
	b[8][5]=true;
	b[8][6]=true;
	b[8][9]=true;
	b[9][8]=true;
	b[9][5]=true;
	b[9][6]=true;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<10;i++)
		{
			c[i]=false;
		}
		bool button=false;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d",&a[i]);
			if(c[a[i]]==false)
			{
				c[a[i]]=true;
			}
			else
			{
				button=true;
			}			
		}
		if(button)
		{
			printf("invalid\n");
			continue;
		}
		for(int i=1;i<k;i++)
		{
			int m=a[i-1];
			int n=a[i];
			if(b[m][n]==false)
			{
				button=true;
				break;
			}
		}
		if(button)
		{
			printf("invalid\n");
		}
		else
		{
			printf("valid\n");
		}
	}
	return 0;
}
