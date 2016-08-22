#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define maxn 120
#define inf 0x3f3f3f3f
int m,n;
vector<int>point[maxn];
vector<int>sale[maxn];
int val[maxn],place[maxn],num_replace[maxn];
int dfs(int st,int cost)
{
    if(point[st].size()==0)
    {
        return cost+val[st];
    }
    else
    {
        int mintemp=cost + val[st];
        for(int i=0;i<point[st].size();i++)
        {
			if (abs(place[st] - place[point[st][i]]) <= m)
			{
				int temp = dfs(point[st][i], cost + sale[st][i]);
				if (temp < mintemp)
				{
					mintemp = temp;
				}
			}
        }
         return mintemp;
    }
}
/*1 4
10000 3 2
2 1
3 3
1000 2 2
4 1
3 1
1000 3 1
4 2
100 4 0  */
int main()
{
	freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&val[i],&place[i],&num_replace[i]);
        int order,sale_money;
        for(int j=1;j<=num_replace[i];j++)
        {
            scanf("%d%d",&order,&sale_money);
            point[i].push_back(order);
            sale[i].push_back(sale_money);
        }
    }
    printf("%d\n",dfs(1,0));
    return 0;
}
