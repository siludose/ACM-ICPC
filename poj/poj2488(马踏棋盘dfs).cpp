#include<iostream>
#include<stack>
#include<string.h>
//#pragma warning(disable:4996)
using namespace std;
int map[100][100];
bool vis[100][100],flag;
int t,maxi,maxj;
int tx[8]={-2,-2,-1,-1,1,1,2,2};
int ty[8]={-1,1,-2,2,-2,2,-1,1};
stack<int>qi,qj;
stack<int>q1, q2;
void dfs(int si,int sj)
{
    vis[si][sj]=true;
    qi.push(si);
    qj.push(sj);
    if(qi.size()==(maxi*maxj))
    {
        flag=true;
        return;
    }
    for(int k=0;k<8;k++)
    {
        int newi=si+tx[k];
        int newj=sj+ty[k];
        if(newi>=1&&newi<=maxi&&newj>=1&&newj<=maxj)
        {
            if(!vis[newi][newj]&&!flag)
            {
                dfs(newi,newj);
            }
        }
    }
    if(!flag)
    {
        vis[si][sj]=false;
        qi.pop();
        qj.pop();        
    }
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    int count=0;
    while(t--)
    {
		memset(vis, 0, sizeof(vis));
        printf("Scenario #%d:\n",++count);
        flag=false;
        scanf("%d%d",&maxj,&maxi);
        dfs(1,1);
        if(flag)
        {
            while(!qi.empty())
            {
				q1.push(qi.top());
				q2.push(qj.top());
                qi.pop();qj.pop();
            }
			while (!q1.empty())
			{
				printf("%c%d", q1.top() + 'A' - 1, q2.top());
				q1.pop(); q2.pop();
			}
            printf("\n\n");
        }
        else
        {
            printf("impossible\n\n");
        }
    }

    return 0;
}
