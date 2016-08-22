#include<iostream>
#define maxn 110
using namespace std;
int n,tot;
int C[maxn],vis[3][maxn];
void search(int cur)
{
	if(cur==n)
	{
		tot++;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			 if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n])
			 {
			 	C[cur]=i;
			 	vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
			 	search(cur+1);
			 	vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
			 }
		}
	}
}
int main()
{
	while(cin>>n)
	{
		tot=0; 
		search(0);
		printf("%d\n",tot);
	}
}
