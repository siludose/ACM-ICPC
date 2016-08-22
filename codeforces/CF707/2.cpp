#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h> 
#pragma warning(disable:4996)
using namespace std;
int n,m,k,num;
int u,v,l;
const int maxn=100010;
vector<int>to[maxn];
vector<int>pay[maxn];
int kk[maxn];
bool kkk[maxn];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    memset(kkk,0,sizeof(kkk));
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&l);
        to[u].push_back(v);
        to[v].push_back(u);
        pay[u].push_back(l);
        pay[v].push_back(l);
    }
    int mi=0x3f3f3f3f;
    for(int i=0;i<k;i++){
        scanf("%d",&kk[i]);
        kkk[kk[i]]=true;
    }
    for(int i=0;i<k;i++)
    {
        int num=kk[i];
        for(int j=0;j<to[num].size();j++)
        {
            int nex=to[num][j];
            if(kkk[nex])continue;
            if(mi>pay[num][j])
            {
                mi=pay[num][j];
            }
        }
    }
    if(mi==0x3f3f3f3f)
        printf("%d\n",-1);
    else
        printf("%d\n",mi);

    return 0;
}
