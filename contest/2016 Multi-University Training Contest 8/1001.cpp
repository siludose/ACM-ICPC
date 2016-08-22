#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include<string.h>
using namespace std;
#define maxn 1010
#define inf 0x3f3f3f3f
multiset<int>s1[maxn];
int t,n,c;
int a[maxn],b[maxn];
int l[maxn],r[maxn];
bool flag;
bool vis[maxn];
bool buu[maxn];
void dfs(int i)
{
    if(i==n)
    {
        flag=1;return;
    }
    set<int>::iterator it;
    for(it=s1[i].begin();it!=s1[i].end();it++)
    {
        if(!vis[*it])
        {
            vis[*it]=true;
            dfs(i+1);
            vis[*it]=false;
        }
    }

}
int main()
{
    freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        flag=0;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        for(int i=0;i<c;i++)
            scanf("%d%d",&l[i],&r[i]);
        for(int i=0;i<n;i++)
            s1[i].insert(i);
        set<int>::iterator it;
        for(int i=0;i<n;i++)
        {
			memset(buu, 0, sizeof(buu));
            for(int j=0;j<c;j++)
            {
            	set<int>::iterator it1;
            	set<int>::iterator it2;
            	
                it1=s1[i].begin();
				it2 = s1[i].end();
				it2--;
    			if(  ((*it1<=l[j])&&(*it2>=l[j]))  ||   ((l[j]<=*it1)&&(r[j]>=*it1))   ||   ((*it1<=l[j])&&(*it2>=r[j])) ||((l[j]<=*it1)&&(r[j]>=*it2)))
    			{
    				for(int k=l[j];k<=r[j];k++)
    				{
    					if(!buu[k])
    						s1[i].insert(k);
					}
				}
                
            }
        }
        for(int i=0;i<n;i++)
        {
            for(it=s1[i].begin();it!=s1[i].end();it++)
            {
                if(a[*it]!=b[i])
                {
                    s1[i].erase(it);
                }
            }
        }
        dfs(0);
        if(flag)
        	printf("Yes\n");
        else
        	printf("No\n");
    }
    return 0;
}
