#include<iostream>  
#include<stdio.h>  
#include<algorithm>  
#include<string.h>  
#include<math.h>  
#include<map>  
#include<queue>  
#include<stack>  
#include<set>
#define maxn 120000
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int t,n,m,n_num;
int sum[maxn<<2];
void pushup(int rt)
{
    if(sum[rt<<1])
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&point[rt]);
    }
    int m=((r-l)+l)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        scanf("%d",&n_num);
        build(1,n,1);
    }
    return 0;
}