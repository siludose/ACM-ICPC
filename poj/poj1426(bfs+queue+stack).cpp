#include<iostream>
#include<queue>
#include<stack>
#include<cstdio>
//#pragma warning(disable:4996)
#define N 4000
using namespace std;
struct Node
{
    int t;
    int pre;
    int index;
    int yu;
}node[N];
int n;
queue<Node>q;
stack<int>s;
void bfs()
{
    int num=0;
    node[num].t=1;
    node[num].yu=1;
    node[num].index=num;
    node[num].pre=0;
    q.push(node[num]);
    while(!q.empty())
    {
        struct Node temp=q.front();q.pop();
        if((temp.yu*10+1)%n==0)
        {
            int te=temp.index;
            s.push(1);
            while(node[te].index!=0)
            {
                s.push(node[te].t);
                te=node[te].pre;
            }
            s.push(1);
            break;
        }
        else
        {
            node[++num].yu=(temp.yu*10+1)%n;
            node[num].t=1;
            node[num].index=num;
            node[num].pre=temp.index;
            q.push(node[num]);
        }
        if((temp.yu*10)%n==0)
        {
            int te=temp.index;
            s.push(0);
            while(node[te].index!=0)
            {
                s.push(node[te].t);
                te=node[te].pre;
            }
            s.push(1);
            break;
        }
        else
        {
            node[++num].yu=(temp.yu*10)%n;
            node[num].t=0;
            node[num].index=num;
            node[num].pre=temp.index;
            q.push(node[num]);
        }   
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    while(scanf("%d",&n)&&n)
    {
        if(n==1)
        {
            printf("%d",1);
            continue;
        }           
        bfs();
        while(!s.empty())
        {
            printf("%d",s.top());
            s.pop();
        }
        printf("\n");
        while (!q.empty())
        {
            q.pop();
        }
    }
    return 0;
}

