#include<iostream>
using namespace std;
#define maxn 301000
int n,k,i,j,l,r,ans;
int a[maxn];

void solve()
{
    i=l=1;
    j=r=0;
    ans=0;
    int cnt=0;
    while(i<=n)
    {
        while(j<=n&&cnt<k)
        {
            j++;
            if(!a[j])
                cnt++;
        }
        while(j<n&&a[j+1])
        {
            j++;
        }
        if(ans<j-i+1)
        {
            ans=j-i+1;
            l=i;r=j;
        }
        if(!a[i])
            cnt--;
        i++;
    }
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    solve();
    for(int i=l;i<=r;i++)
    {
        a[i]=1;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
