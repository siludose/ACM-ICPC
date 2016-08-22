#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
#define maxn 1010
int a[maxn],b[maxn],c[maxn],d[maxn];
int t,n,m;
vector<int>v[maxn];
int main()
{
    freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
    	memset(c,0,sizeof(c));
    	memset(d,0,sizeof(d));
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
        	scanf("%d",&a[i]);
        	c[a[i]]++;
		}
        for(int i=0;i<n;i++)
        {
        	scanf("%d",&b[i]);
        	d[b[i]]++;
		}
		int i;
        for(i=0;i<n;i++)
        {
        	if(c[i]!=d[i])
        	{
        		break;
			}
		}
		if(i!=n)
		{
			printf("No\n");continue;
		}
        for(int i=0;i<n;i++)
        {
            v[i].push_back(1);
        }
        for(int i=0;i<n;i++)
        {
            v[b[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            int num=v[a[i]][0];
            a[i]=v[a[i]][num];
            v[a[i]][0]++;
        }
        for(int i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
