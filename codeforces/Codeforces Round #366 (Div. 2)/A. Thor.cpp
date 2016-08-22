#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<queue>
using namespace std;
#define maxn 300100
int n,t;
int x,y;
queue< pair<int,int> >q[maxn];
int vis[maxn];
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        int sum=0,num=0;
        for(int i=0;i<t;i++)
        {
            scanf("%d%d",&x,&y);
            //printf("%d %d\n",x,y);
            switch(x)
            {
                case 1:
                {
                    vis[num]=y;
                    q[y].push(make_pair(num++,y));
                    sum++;
                    printf("%d\n",sum);
                    break;
                }
                case 2:
                {
                    while(!q[y].empty())
                    {
                        int temp=q[y].front().first;
                        vis[temp]=-1;
                        q[y].pop();
                        sum--;
                    }
                    printf("%d\n",sum);
                    break;
                }
                case 3:
                {
                    for(int i=0;i<y;i++)
                    {
                    	if(vis[i]!=-1)
                    	{
                    		q[vis[i]].pop();
                    		vis[i]=-1;
                    		sum--;
						}
					}
                    printf("%d\n",sum);
                    break;
                }
            }
            /*for(int i=1;i<=n;i++)
            {
            	printf("%d ",q[i].size());
			}printf("\n");*/
        }
    }
    return 0;
}
