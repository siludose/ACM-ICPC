int pre[maxn];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        pre[i]=i;
    }
}
int find(int x)
{
    int r=x;
    while(pre[r]!=r)
    {
        r=pre[r];
    }
    int i=x,j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
    {
        pre[fx]=fy;
    }
}