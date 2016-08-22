#include<cstdio>
#include<cstring>
long long f[30][1<<12],i,j,n,m,saya=1;
void sayatime (int i,int s1,int pos)
{
    if (pos==m) {f[i][s1]+=saya;return;}
    sayatime(i,s1,pos+1);
    if (pos<=m-2&&!(s1&1<<pos)&&!(s1&1<<pos+1)) sayatime(i,s1|1<<pos|1<<pos+1,pos+2);
}
int main()
{
    
    while(scanf("%d%d",&n,&m),n!=0)
    {
        memset(f,0,sizeof(f));saya=1;
        sayatime(1,0,0);
        for (i=2;i<=n;i++)
        for (j=0;j<1<<m;j++)
        {
            if (f[i-1][j]) saya=f[i-1][j]; else continue;
            sayatime(i,~j&((1<<m)-1),0);
        }
        printf("%lld\n",f[n][(1<<m)-1]);
    }
}
/*用2进制的01表示不放还是放
第i行只和i-1行有关
枚举i-1行的每个状态，推出由此状态能达到的i行状态
如果i-1行的出发状态某处未放，必然要在i行放一个竖的方块，
所以我对上一行状态按位取反之后的状态就是放置了竖方块的状态。
然后用搜索扫一道在i行放横着的方块的所有可能，
并且把这些状态累加上i-1的出发状态的方法数，如果该方法数为0，直接continue。
举个例子
2 4
1111
1111
状态可以由
1100 0000 0110 0011 1111
0000 0000 0000 0000 0000
这五种i-1的状态达到，故2 4 的答案为5*/
#include<iostream>
#include<cstring>
using namespace std;
long long f[2][1<<12],i,j,ps,p=0,c=1,n,m;
int main()
{
    while (scanf("%d%d",&n,&m),n!=0)
    {
    memset(f[c],0,sizeof(f[c]));
    f[c][(1<<m)-1]=1;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
        {
            swap(p,c);memset(f[c],0,sizeof(f[c]));
            for (ps=0;ps<1<<m;ps++)
            if (f[p][ps])
            {
                if (j>0&&(!(ps&(1<<j-1)))&&(ps&(1<<j))) f[c][ps|1<<(j-1)]+=f[p][ps];
                if (!(ps&1<<j)) f[c][ps|1<<j]+=f[p][ps];
                if (ps&1<<j) f[c][ps^1<<j]+=f[p][ps];
            }
        }
    printf("%lld\n",f[c][(1<<m)-1]);
    }
}