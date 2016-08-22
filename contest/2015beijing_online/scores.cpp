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
�ֶ������ˡ�����������ָ��Ҫ���Ĳ�����һ��ָ�����һ��ָ��ó��Ĵ�
����˵��ʲôdktree�ҷ��������������Ŀ��Ԥ����o(5n),��ʽ������o(5*(log2n+sqrt(n)))�������ò���ģ���㷨
��֮����˼·���ȷ�sqrt(n)�δ���ÿһ�εļ��϶�����һ������ļ��ϰ���
֮��ָ���ѯʱ���ö�������𰸺��������Σ��ӽ�����Ŀ���ϣ�Ȼ����sqrt(n)�ΰѲ���ȫ������������֣��ӽ�����Ŀ����
��Ϊʲô����50000��״̬�������ˣ���Ϊ�����ᱬ�ڴ棬50000*50000�����������ĸ���Ŀ�����������ģ�
�����ַ�ʽ���5����Ŀ�ļ��ϣ��ٰ���5�������󽻼�����ʱ�������ϻ�����1�����󣬾���ֻ�뵽����ƫ���ϵȥ��ûת��˼·��
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