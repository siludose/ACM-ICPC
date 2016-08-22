#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 155000
struct People
{
    char name[210];
    int v;
    int n;
}P[maxn];
struct door
{
    int num;
    int p;
}d[maxn];
bool cmp1(door a, door b)
{
    return a.num < b.num;
}
int k, m, q, t;
struct cmp
{
    bool operator()(People a, People b) {
        if (a.v != b.v)
            return a.v < b.v;
        else
            return a.n > b.n;
    }
};
priority_queue<People, std::vector<People>, cmp> peo;
vector<int>ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &k, &m, &q);
        for (int i = 0; i<k; i++)
        {
            scanf("%s %d",P[i].name,&P[i].v);
            P[i].n = i;
        }
        int  x;
        int nownum = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &d[i].num, &d[i].p);
        }
        sort(d, d + m, cmp1);
        for (int i = 0; i<m; i++)
        {
            int j;
            for (j = nownum; j<d[i].num; j++)
            {
                peo.push(P[j]);
            }
            nownum = j;
            while (d[i].p--)
            {
                if (peo.empty())
                    break;
                ans.push_back(peo.top().n);
                peo.pop();
            }
        }
        for (int j = nownum; j<k; j++)
        {
            peo.push(P[j]);
        }
        while (!peo.empty())
        {
            ans.push_back(peo.top().n);
            peo.pop();
        }
        while (q--)
        {
            scanf("%d", &x);
            if (q == 0)
            {
                printf("%s", P[ans[x - 1]].name);
            }
            else
            {
                printf("%s ", P[ans[x - 1]].name);
            }        
        }
        printf("\n");
        ans.clear();
    }
    return 0;
}