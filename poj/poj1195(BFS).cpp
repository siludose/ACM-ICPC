#include<iostream>
#include<cstdio>
//#pragma warning(disable:4996)
using namespace std;
int o,n,MaxVal;
int tree[1050][1050];
void update(int x,int y, int num)
{
    int temp;
    while (x <= n)
    {
        temp = y;
        while (temp <= n)
        {
            tree[x][temp] = tree[x][temp] + num;
            temp +=temp&(-temp);
        }
        x +=x&(-x);
    }
}
int sum(int x,int y)
{
    int ans=0;
    int temp;
    while (x > 0)
    {
        temp = y;
        while (temp>0)
        {
            ans += tree[x][temp];
            temp -= (temp&-temp);
        }
        x -= x&(-x);
    }   
    return ans;
}
void init(int num)
{
    for (int i = 0; i <= num; i++)
    {
        for (int j = 0; j <= num; j++)
        {
            tree[i][j] = 0;
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    bool button=true;
    while(button)
    {
        scanf("%d",&o);
        switch(o)
        {
            case 0:
            {
                scanf("%d",&n);
                init(n);
                break;
            }
            case 1:
            {
                int x,y,v;
                scanf("%d %d %d",&x,&y,&v);
                update(x+1,y+1,v);
                break;
            }
            case 2:
            {
                int l,b,r,t,ans=0;
                scanf("%d%d%d%d",&l,&b,&r,&t);

                ans += sum(r + 1, t + 1);
                ans += sum(l, b);
                ans -= sum(l, t + 1);
                ans -= sum(r + 1, b);

                cout<<ans<<endl;
                break;
            }
            case 3:
            {
                button=false;
                break;
            }
        }
    }   
    return 0;
}