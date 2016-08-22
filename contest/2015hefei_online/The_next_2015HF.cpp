/*
算是合肥赛区的水题 
不应该被位操作吓着，可以转换为简单的构造题目，
首先将d++，然后开始实时跟踪其二进制为1的个数
接下来如果sum小于s1，那就在最小的为0的位置置为3
如果sum大于s2，那就在最小的为1的位置加1，争取前一位也为1，减少sum的个数
让以上步骤形成循环 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 50
#define ll long long
ll d;
int s1,s2,t;
bool D[maxn];
int main()
{
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(D,0,sizeof(D));
        scanf("%I64d",&d);
        scanf("%d%d",&s1,&s2);
        d++;int sum=0;
        for(int i=0;i<=31;i++)
            if(d&((ll)1<<i))
                {D[i]=true;sum++;}
        while(1)
        {
            if(sum>=s1&&sum<=s2)
            {
                printf("Case #%d: %I64d\n",cas,d);
                break;
            }
            if(sum<s1)
            {
                int x=0;
                while(D[x]!=false)
                    x++;
                D[x]=true;
                d^=(ll)1<<x;
                sum++;
            }
            else if(sum>s2)
            {
                int x=0;
                while(D[x]==false)
                    x++;
                d+=(ll)1<<x;
                memset(D,0,sizeof(D));sum=0;
                for(int i=0;i<=31;i++)
                    if(d&((ll)1<<i))
                        {D[i]=true;sum++;}
            }
        }
    }
    return 0;
}
