#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define maxn 100010
int t,n,m;
int a[maxn];
int b[maxn];
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
    	memset(b,0,sizeof(b));
    	b[0]=1; 
    	bool flag=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==m)flag=true;
           	a[i]+=a[i-1]; 
           	if(b[a[i]%m]!=0)
           	{
           		flag=true;
           	} 
           	b[a[i]%m]++;
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}
