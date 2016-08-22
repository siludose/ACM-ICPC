#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define maxn 10000
bool vis[maxn];
int n,a;
queue<int>que;
int main()
{
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(vis[a])
        {
            que.push(a);
        }
        else
        {
            vis[a]=true;
        }
    }
    while(!que.empty())
    {
        int p=que.front();
        que.pop();
        int temp=p;
        while(1)
        {
            if(!vis[temp])
            {
                ans+=temp-p;
                vis[temp]=true;
                break;
            }
            else
            {
                temp++;
            }
        }
    }
    cout<<ans;
    return 0;
}
