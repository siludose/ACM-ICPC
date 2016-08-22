#include<iostream>
//#pragma warning(disable:4996)
using namespace std;
const int maxn=110;
int n,m,num;
int lan[maxn];
bool G[maxn][maxn];
int pre[maxn];
bool lan_need[maxn];
bool lan_find[maxn];
int find(int x)
{
    int r=x;
    while(pre[r]!=r)
    {
        r=pre[r];
    }
    int i=x,j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
    {
        pre[fx]=fy;
    }
}
int main()
{
	int ans=0;
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);    
    for(int i=0;i<maxn;i++)
    {
        pre[i]=i;
    }
    for(int k=0;k<n;k++)
    {
        scanf("%d",&num);
        if(num==0)
        {
        	ans++;
        	continue;
		}
        for(int i=0;i<num;i++)
        {
            scanf("%d",&lan[i]);
            lan_need[lan[i]]=true;
        }
        for(int i=0;i<num;i++)
        {
            for(int j=i+1;j<num;j++)
            {
                G[lan[i]][lan[j]]=true;
                G[lan[j]][lan[i]]=true;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            if(lan_need[i]&&lan_need[j])
            {
                if(G[i][j])
                {
                    join(i,j);
                }
            }
        }
    }
    bool button=true;
    while(button)
    {
		button = false;
        for(int i=1;i<=m;i++)
        {
            if(lan_need[i])
            {
                int temp=find(i);
                if(lan_find[temp]==false)
                {
                    lan_find[temp]=true;
                    ans++;
                }
            }
        }
    }
    cout<<ans-1<<endl;
	return 0;
}
