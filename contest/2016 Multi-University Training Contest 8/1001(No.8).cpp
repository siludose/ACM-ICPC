#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
#define maxn 1010
int a[maxn],b[maxn],c[maxn],d[maxn];
int t,n,m;
int l[maxn], r[maxn];
int num[maxn];
vector<int>v[maxn];

int main()
{
    freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
    	memset(c,0,sizeof(c));
    	memset(d,0,sizeof(d));
		memset(num, 0, sizeof(num));
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
        	scanf("%d",&a[i]);
        	c[a[i]]++;
		}
        for(int i=0;i<n;i++){
        	scanf("%d",&b[i]);
        	d[b[i]]++;
		}
		for (int i = 0; i < m; i++) 
			scanf("%d%d", &l[i], &r[i]);
		
		

		int k;
        for(k=0;k<n;k++)
        	if(c[k]!=d[k])
        		break;
		if(k!=n){printf("No\n");continue;}

        for(int i=0;i<n;i++)
            v[b[i]].push_back(i);

		for(int i=0;i<n;i++){ 
			int temp = a[i];
            a[i]=v[a[i]][num[a[i]]];
			num[temp]++;
        }

		for (int i = 0; i < m; i++)
		{
			sort(a + l[i]-1, a + r[i]);
		}
		bool flag = true;
		for (int i = 0; i < n; i++)
			if (a[i] != i)
			{
				flag = false; break;
			}

		if (flag)
			printf("Yes\n");
		else
			printf("No\n");

		for (int i = 0; i < maxn; i++)
		{	
			v[i].clear();
		}
    }
    return 0;
}
