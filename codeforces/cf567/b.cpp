#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 1000010
int n;bool a[maxn];
#define max(a,b) a>b?a:b
int main()
{
    scanf("%d",&n);
    int num=0,k;char c[3];
    int maxnum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s %d",c,&k);
        if(c[0]=='-')
        {
        	if(a[k])
        	{
        		num--;
        		a[k]=false;
			}
			else
			{
				maxnum++;
			}
		}
        else
        {
        	a[k]=true;
        	num++;
        	maxnum=max(num,maxnum);
		}
    }
    printf("%d\n",maxnum);
    return 0;
}
