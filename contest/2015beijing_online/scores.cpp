#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 1006
#define mod 1000000007
#define eps 1e-9
#define PI acos(-1)
const double EP  = 1E-10 ;
int Num;
//const int inf=0x7fffffff;
const ll inf=999999999;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//*************************************************************************************

bitset<50001> b[7][270];
bitset<50001> Ans[7];
int now[7];
struct node
{
    int x,y;
};
bool cmp(node a,node b)
{
    return a.x<b.x;
}
node a[7][50001];
int l[300],r[300];
int belong[50001];
/*
又读错题了。。。这后面的指令要异或的不是上一条指令，是上一条指令得出的答案
网上说的什么dktree我反正不懂，这道题目的预处理o(5n),正式开干是o(5*(log2n+sqrt(n)))，根本用不到模板算法
总之懂了思路：先分sqrt(n)段处理，每一段的集合都有上一段求出的集合包含
之后指令查询时先用二分求出答案含的整条段，加进本科目集合，然后用sqrt(n)次把不完全段里的所有数字，加进本科目集合
（为什么不把50000个状态都储存了，因为这样会爆内存，50000*50000的数据量，哪个题目会允许这样的）
以这种方式求出5个科目的集合，再把这5个集合求交集（那时在赛场上还犯了1个错误，就是只想到利用偏序关系去求，没转换思路）
*/
int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int n=read(),m=read();
        for(int i=1;i<=5;i++)
            for(int j=1;j<250;j++)
                b[i][j].reset();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=5;j++)
            {
                a[j][i].x=read();
                a[j][i].y=i;
            }
        }
        for(int i=1;i<=5;i++)
            sort(a[i]+1,a[i]+n+1,cmp);
        int block = sqrt((double)n);
        int num = n/block;
        if(n%block)num++;
        for(int i=1;i<=num;i++)
            l[i]=(i-1)*block+1,r[i]=i*block;
        r[num]=n;
        for(int i=1;i<=n;i++)
            belong[i]=(i-1)/block+1;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=num;j++)
            {
                b[i][j]|=b[i][j-1];
                for(int k=l[j];k<=r[j];k++)
                    b[i][j][a[i][k].y]=1;
            }
        }
        int q=read();
        int lastans = 0;
        while(q--)
        {
            for(int i=1;i<=5;i++)
                now[i]=read();
            for(int i=1;i<=5;i++)
                now[i]^=lastans;
            for(int i=1;i<=5;i++)
                Ans[i].reset();
            for(int i=1;i<=5;i++)
            {
                int L = 0,R = n;
                while(L<=R)
                {
                    int mid = (L+R)/2;
                    if(now[i]>=a[i][mid].x)
                        L = mid+1;
                    else
                        R = mid-1;
                }
                int p = L-1;
                if(p==0)continue;
                Ans[i]|=b[i][belong[p]-1];
                for(int j=l[belong[p]];j<=p;j++)
                    Ans[i][a[i][j].y]=1;
            }
            Ans[1] = Ans[1]&Ans[2]&Ans[3]&Ans[4]&Ans[5];
            lastans = Ans[1].count();
            printf("%d\n",lastans);
        }
    }
}