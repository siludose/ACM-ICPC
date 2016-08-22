#include<iostream>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 10
int n,k,ans;
char map[maxn][maxn];
bool vis[maxn];
void dfs(int i,int countt)
{
	if(countt==k)
	{
		ans++;
		return;
	}
	if(i>n)
	{
		return;
	}
	for(int j=1;j<=n;j++)
	{
		if(map[i][j]=='#'&&(!vis[j]))
		{
			vis[j] = true;
			dfs(i+1,countt+1);
			vis[j] = false;
		}
	}
	dfs(i + 1, countt);
}
int main()
{
	//freopen("input.txt","r",stdin);
    while(~scanf("%d%d",&n,&k))
    {
    	if(n==-1&&k==-1)
    		break;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",map[i]+1);
        }
        ans=0;
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
