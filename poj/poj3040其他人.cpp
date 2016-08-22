struct Inf
{
    int v,num;
}inf[22];

int need[22];
int n,c;

bool cmp(struct Inf a,struct Inf b)
{
    return a.v>b.v;
}

int main()
{
   while(~scanf("%d%d",&n,&c))
   {
       for(int i=1;i<=n;i++)
           scanf("%d%d",&inf[i].v,&inf[i].num);

        sort(inf+1,inf+n+1,cmp);
        int ans=0;
        while(true)
        {
            memset(need,0,sizeof(need));
            int sum=c;
            for(int j=1;j<=n;j++)
            {
                int tmp=sum/inf[j].v;
                tmp=min(tmp,inf[j].num);
                need[j]+=tmp; //需要这么多个
                sum-=tmp*inf[j].v; //还剩下的
            }
            if(sum>0) //不能恰好凑齐，用一个满足的最小的补
            {
                for(int j=n;j>=1;j--)
                {
                    if(inf[j].num-need[j]&&inf[j].v>=sum)
                    {
                        need[j]++;
                        sum=0;
                        break;
                    }
                }
            }
            if(sum>0) //再也凑不到了
                break;
            int Min=INF;
            for(int j=1;j<=n;j++)//找到能够凑c的最多次数
                if(need[j])
                    Min=min(Min,inf[j].num/need[j]);
            ans+=Min;
            for(int j=1;j<=n;j++) //减去个数
                inf[j].num-=Min*need[j];
        }
        printf("%d\n",ans);
   }
   return 0;
}
