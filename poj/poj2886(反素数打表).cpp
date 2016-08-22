#include<iostream>
#include<cstdio>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 505000
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
char s[maxn][12];
int c[maxn<<2],v[maxn<<2],nex[maxn<<2];
int n,k,num,pos;
const int antiprime[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,  
                       1260,1680,2520,5040,7560,10080,15120,20160,25200,  
                       27720,45360,50400,55440,83160,110880,166320,221760,  
                       277200,332640,498960,554400,665280  
                      };  
  
const int factorNum[]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,  
                       64,72,80,84,90,96,100,108,120,128,144,160,168,180,  
                       192,200,216,224  
                      };  
void pushup(int rt)
{
    c[rt]=c[rt<<1]+c[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {

        scanf("%s",s[++num]);
        scanf("%d",&nex[rt]);
        v[rt]=num;c[rt]=1;
    }
    else
    {
        int m=(l+r)>>1;
        build(lson);build(rson);
        pushup(rt);
    }
}
void dele(int l,int r,int rt,int index)
{
    if(l==r)
    {
        c[rt]=0;
        pos=rt;
    }
    else
    {
        int m=(l+r)>>1;
        if(index<=c[rt<<1])
        {
            dele(lson,index);
        }
        else
        {
            dele(rson,index-c[rt<<1]);
        }
    }
    pushup(rt);
}
int main()
{
	//freopen("input.txt","r",stdin);
	int &mod = c[1];
    while(~scanf("%d%d",&n,&k))
    {
        num=0;
        build(1,n,1);
        int cnt=0;
		int size_=n;  
        while(cnt<35 && antiprime[cnt]<=n)  
            cnt++;  
        cnt--;
        for(int i=0;i<antiprime[cnt];i++)
        {
			dele(1, n, 1, k); if (mod == 0)break;
			if (nex[pos] > 0)
				k = ((k + nex[pos] - 2) % mod + mod) % mod + 1;
			else
				k = ((k + nex[pos] - 1) % mod + mod) % mod + 1;                 
        }
        printf("%s %d\n",s[v[pos]],factorNum[cnt]);
    }
    return 0;
}
