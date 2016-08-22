#include<iostream>
#include<string.h>
#include<vector>
#include<cstdio>
using namespace std;
#define mod 999983
#define ll long long 
#define maxx 1000000000 
int n,k;
vector< pair<int,int> >hash[mod];
int b[200005];
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    int a,ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        b[i]=a;
        int key=(a%mod+mod)%mod;
        hash[key].push_back(make_pair(a,i));
    }
    for(int i=0;i<n;i++)
    {
        ll temp=(ll)b[i]*k;
        if(temp>maxx)
            continue;
        int key=(temp%mod+mod)%mod;
        for(int j=0;j<hash[key].size();j++)
        {
            int index=hash[key][j].second;
            if(hash[key][j].first==temp&&index>i)
            {
                ll tmp=(ll)temp*k;
                int key1=(tmp%mod+mod)%mod;
                for(int x=0;x<hash[key1].size();x++)
                {
                    if(hash[key1][x].first==tmp&&hash[key1][x].second>index)
                    {
                        ans++;
                    }
                }
            
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
