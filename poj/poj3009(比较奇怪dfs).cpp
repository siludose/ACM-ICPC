#include<iostream>
//#pragma warning(disable:4996)
using namespace std;
#define inf 0x7fffffff
int w,h,si,sj,ei,ej;
int map[25][25];
int minstep,numstep;
bool flag=0;
int di[4]={0,1,0,-1};
int dj[4]={-1,0,1,0};
void dfs(int si,int sj,bool moving,int dir)
{
    if(numstep>10)
    {
		return;
    }
    if(map[si][sj]==3)
    {
        if(numstep<minstep)
            minstep=numstep;
        return ;
    }
    if(moving)
    {
        if(map[si][sj]==0)
        {
            int newi=si+di[dir];
            int newj=sj+dj[dir];
            if(newi>=0&&newj>=0&&newi<=h&&newj<=w)
            {
                //dfs(newi,newj,1,dir);
				if (map[newi][newj] == 1)
				{
					map[newi][newj] = 0;
					dfs(si, sj, 0, -1);
					map[newi][newj] = 1;
				}
				else
				{
					dfs(newi, newj, 1, dir);
				}
            }
        }
        else
        {
            dfs(si,sj,0,-1);
        }
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            int newi=si+di[i];
            int newj=sj+dj[i];
            if(newi>=0&&newj>=0&&newi<=h&&newj<=w)
            {
				if (map[newi][newj] != 1)
				{
					numstep++; dfs(newi, newj, 1, i); numstep--;
				}              
            }
        }
    }

}
int main()
{
    //freopen("input.txt","r",stdin);
    while(~scanf("%d%d",&w,&h))
    {
        if(w==0||h==0)
        {
            break;
        }
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                scanf("%d",&map[i][j]);
                if(map[i][j]==2)
                {
                    si=i,sj=j;
                }
            }
        }
        minstep=inf;
        numstep=0;
        map[si][sj]=0;
        dfs(si,sj,0,-1);
        
        if(minstep!=inf)
        	cout<<minstep<<endl;
        else
        	cout<<-1<<endl;
    }
    return 0;
}
