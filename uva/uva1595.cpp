#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int x[N], y[N], n, mx;

bool have(int i)
{
    for(int j = 0; j < n; ++j)
        if(y[i] == y[j] && x[i] + x[j] == 2 * mx) return true;
    return false;
}

int main()
{
    int cas, lx, rx, a, i;
    scanf("%d", &cas);
    while(cas--)
    {
        lx = rx = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d%d", &a, &y[i]);
            x[i] = a * 2;
            if(x[i] < x[lx]) lx = i;
            if(x[i] > x[rx]) rx = i;
        }
        mx = (x[lx] + x[rx]) / 2;
        for(i = 0; i < n; ++i)
            if(!have(i)) break;

        if(i >= n) puts("YES");
        else puts("NO");
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define maxn 20000+10
#define c 10000
using namespace std;
vector<int> v[maxn];
int N,a[maxn],cnt[maxn];
double mid;
int equal(double a,double b)
{
    return fabs(a-b)>1e-6?0:1;
}
int main()
{
    int T,top=0;
    cin>>T;
    while (T-->0)
    {
        cin>>N;
        top=0;
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        int x,y;
        while(N-->0){
            cin>>x>>y;
            x+=c;
            y+=c;
            if (!a[y]) a[y]=++top;
            v[a[y]].push_back(x);
            cnt[a[y]]++;
        }
        for (int i=1;i<=top;i++)
            sort(v[i].begin(),v[i].end());
        mid=(v[1][cnt[1]-1]+v[1][0])/2.0;
        int k,p,q,ok=1;
        for (k=1;k<=top;k++)
        {
            p=0;
            q=cnt[k]-1;
            while (p<=q&&ok)
                if (!equal(mid-v[k][p++],v[k][q--]-mid)) ok=0;
            if (!ok) break;
        }
        if (ok) cout<<"YES"<<endl;else cout<<"NO"<<endl;
        for (int i=1;i<=top;i++)
            v[i].clear();
    }
}