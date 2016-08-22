const int INF=0x3f3f3f3f;
const int MAXN=110;
bool vis[MAXN];
int lowc[MAXN];
int Prim(int cost[][MAXN],int n)
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    vis[0]=true;
    for(int i=1;i<n;i++)
        lowc[i]=cost[0][i];
    for(int i=1;i<n;i++)
    {
        int minc=INF;
        int p=-1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        }
        if(minc==INF)return -1;
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<n;j++)
            if(!vis[j]&&lowc[j]>cost[p][j])
                lowc[i]=vost[p][j];
    }
    return ans;
}