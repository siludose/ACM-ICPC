#include<iostream>
#include<map>
#include<string>
#include<string.h>
//#pragma warning(disable:4996)
#define maxn 35
int n,m;
double rate;
const int inf=10000;

using namespace std;
double dist[maxn][maxn];
char str1[50],str2[50];
map<string,int>s;
void floyd()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<dist[i][k]*dist[k][j])
                {
                    dist[i][j]=dist[i][k]*dist[k][j];
                }
            }
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int count=1;
    while(scanf("%d",&n),n)
    {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = inf;
			}
		}
        for(int i=0;i<n;i++)
        {
            scanf("%s",str1);
            s[str1]=i;
            dist[i][i]=1;
        }
		scanf("%d", &m);
        for(int i=0;i<m;i++)
        {
			cin >> str1 >> rate >> str2;
            dist[s[str1]][s[str2]]=rate;
        }

        floyd();

        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(dist[i][i]>1)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            printf("Case %d: Yes\n",count++);
        }
        else
        {
            printf("Case %d: No\n",count++);
        }
    }
    return 0;
}
