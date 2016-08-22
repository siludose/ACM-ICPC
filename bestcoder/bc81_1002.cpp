#include<iostream>
#include<string.h>
using namespace std;
#define maxn 1200

int t;
int L[maxn],H[maxn];
__int64 a[maxn][maxn];
int o,x,y;
int n,m,q;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&q);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%I64d",&a[i][j]);
            }
        }
        for(int i=1;i<=max(n,m);i++)
        {
            H[i]=i;L[i]=i;
        }
        while(q--)
        {
            scanf("%d%d%d",&o,&x,&y);
            switch(o)
            {
                case 1:
                {
                	int temp=H[x];
                    H[x]=H[y];
                    H[y]=temp;
                    break;
                }
                case 2:
                {
                	int temp=L[x];
                    L[x]=L[y];
                    L[y]=temp;
                    break;
                }
                case 3:
                {
                    for(int i=1;i<=m;i++)
                        a[H[x]][L[i]]+=y;
                    break;
                }
                case 4:
                {
                    for(int i=1;i<=n;i++)
                        a[H[i]][L[x]]+=y;
                    break;
                } 
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<m;j++)
            {
                printf("%I64d ",a[H[i]][L[j]]);
            }
            printf("%I64d\n",a[H[i]][L[m]]);
        }
    }
    return 0;
}
