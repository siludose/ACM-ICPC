#include<iostream>
#include<cstdio>
#include<string.h>
//#pragma warning(disable:4996)
using namespace std;
char charmap[15][15];
int map[15][15];
bool ru[10][10];
bool lu[10][10];
bool tu[5][5][10];
int t;
int cnt;
struct node
{
    int x,y;
}q[9*9+10];
bool dfs(int cn)
{
    if(cn<0)return true;
    int x=q[cn].x,y=q[cn].y;

    for(int k=1;k<=9;k++)
    {
       if(ru[x][k]||lu[y][k]||tu[(x-1)/3+1][(y-1)/3+1][k]) continue;
       ru[x][k]=true;lu[y][k]=true;tu[(x-1)/3+1][(y-1)/3+1][k]=true;
       map[x][y]=k;
       if(dfs(cn-1))return true;
       ru[x][k]=0;lu[y][k]=0;tu[(x-1)/3+1][(y-1)/3+1][k]=0;
    }
    return false;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    cnt=0;
    while(t--)
    {
        cnt=0;
        memset(lu, 0, sizeof(lu));
        memset(ru, 0, sizeof(ru));
        memset(tu, 0, sizeof(tu));

        for(int i=1;i<=9;i++)
        {
            cin>>charmap[i]+1;
            for(int j=1;j<=9;j++)
            {
                map[i][j]=charmap[i][j]-'0';
                if(map[i][j]==0)
                {
                    q[cnt++]=(node){i,j};
                    continue;
                }
                else
                {
                    ru[i][map[i][j]]=true;
                    lu[j][map[i][j]]=true;
                    tu[(i-1)/3+1][(j-1)/3+1][map[i][j]]=true;
                }           
            }
        }
        dfs(cnt-1);
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                cout<<map[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}