#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 110
int t,n,m,x,y;
int a[maxn];
int lcd(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;a=b;b=c;
    }
    return a;
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
    	memset(a,-1,sizeof(a));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        if(a[1]==-1)
        {
        	a[1]=100;
        	if(a[2]==-1)
        	{
        		a[2]=100;
			}
		}
		else
		{
			if(a[2]==-1)
			{
				a[2]=a[1];
			}
		}
        int temp=0;
        for(int i=n;i>2;i--)
		{
			if(a[i]==-1)
			{
				a[i]=temp;
			}
			else
			{
				temp=a[i];
			}
		} 
        int sum=0;
        for(int i=1;i<=n;i++)
        {
                sum+=a[i];
        }
        a[1]+=a[2];
        int num=lcd(a[1],sum);
        printf("%d/%d\n",a[1]/num,sum/num);
    }
    return 0;
}
