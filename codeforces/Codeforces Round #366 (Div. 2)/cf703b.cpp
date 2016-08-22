#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 100100
__int64 a[maxn];
int n,k;
__int64 sum,num;
bool vis[maxn];
int main()
{
	memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=0;i<k;i++)
    {
        scanf("%I64d",&num);
        vis[num]=true;
        if(num==1||num==n){
            if(num==1){
                for(int j=3;j<n;j++)
                    {sum+=a[num]*a[j];printf("%I64d %I64d\n",num,j);} 					            
            }else{
                for(int j=2;j<n-1;j++)
                    sum+=a[num]*a[j];
            }
        }else{
            for(int j=1;j<=n;j++)
                if(j!=num-1&&j!=num+1&&j!=num&&!vis[j])
                    {sum+=a[num]*a[j];printf("%I64d %I64d\n",num,j);} 	
        }
    }
    for(int i=1;i<=n-1;i++)
    {
    	sum+=a[i]*a[i+1];printf("%I64d %I64d\n",i,i+1);
	}
    sum+=a[1]*a[n];printf("%I64d %I64d\n",a[1],a[n]);
    printf("%I64d\n",sum);
    return 0;
}
