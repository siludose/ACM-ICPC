#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<string.h>
//#pragma warning(disable:4996)
using namespace std;
#define N 10000
bool vis[N];
bool prime[N];
int step[N];
int a, b, t;
void bfs()
{
	if (a == b)
	{
		cout << 0 << endl;
		return;
	}
    queue<int>q;//把队列设置在函数体里面就不用考虑每次bfs都要清空
    vis[a]=true;
    q.push(a);
    step[a]=0;
    while(!q.empty())
    {
        int num=q.front();q.pop();
        for(int i=1;i<=1000;i*=10)
        {
            for(int j=0;j<10;j++)
            {
                if(i==1000&&j==0)continue;
                int t=num%i+j*i+num/(i*10)*(i*10);
				if (t == b)
				{
					cout << step[num] + 1 << endl;
					return;
				}
                if(prime[t])
                {
                    if(vis[t])
                    {
                        continue;
                    }
                    vis[t]=true;
                    step[t]=step[num]+1;
                    q.push(t);
                }
            }
        }
    }
	cout << "Impossible" << endl;
    return ;
}
int main()
{
	//freopen("input.txt", "r", stdin);
    scanf("%d",&t);
    memset(prime, true, sizeof(prime));
	
    prime[0] = prime[1] = false;
    for(int i=2; i*i<N; i++) {
	  if(prime[i])
		 for(int j=i*i; j<N; j += i) {
			 prime[j] = false;
		 }
    }  
    while(t--)
    {
		memset(step, 0, sizeof(step));
		memset(vis, 0, sizeof(vis));
        scanf("%d%d",&a,&b);
		bfs();
    }
    return 0;
}