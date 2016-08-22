#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <algorithm>  
using namespace std;  
#define Del(a,b) memset(a,b,sizeof(a))  
const int N = 10005;  
  
int dep[N],siz[N],fa[N],id[N],son[N],val[N],top[N]; //top 最近的重链父节点  
int num;  
vector<int> v[N];  
struct tree  
{  
    int x,y,val;  
    void read(){  
        scanf("%d%d%d",&x,&y,&val);  
    }  
};  
tree e[N];  
void dfs1(int u, int f, int d) {  
    dep[u] = d;  
    siz[u] = 1;  
    son[u] = 0;  
    fa[u] = f;  
    for (int i = 0; i < v[u].size(); i++) {  
        int ff = v[u][i];  
        if (ff == f) continue;  
        dfs1(ff, u, d + 1);  
        siz[u] += siz[ff];  
        if (siz[son[u]] < siz[ff])  
            son[u] = ff;  
    }  
}  
void dfs2(int u, int tp) {  
    top[u] = tp;  
    id[u] = ++num;  
    if (son[u]) dfs2(son[u], tp);  
    for (int i = 0; i < v[u].size(); i++) {  
        int ff = v[u][i];  
        if (ff == fa[u] || ff == son[u]) continue;  
        dfs2(ff, ff);  
    }  
}  
#define lson(x) ((x<<1))  
#define rson(x) ((x<<1)+1)  
struct Tree  
{  
    int l,r,val;  
};  
Tree tree[4*N];  
void pushup(int x) {  
    tree[x].val = max(tree[lson(x)].val, tree[rson(x)].val);  
}  
  
void build(int l,int r,int v)  
{  
    tree[v].l=l;  
    tree[v].r=r;  
    if(l==r)  
    {  
        tree[v].val = val[l];  
        return ;  
    }  
    int mid=(l+r)>>1;  
    build(l,mid,v*2);  
    build(mid+1,r,v*2+1);  
    pushup(v);  
}  
void update(int o,int v,int val)  //log(n)  
{  
    if(tree[o].l==tree[o].r)  
    {  
        tree[o].val = val;  
        return ;  
    }  
    int mid = (tree[o].l+tree[o].r)/2;  
    if(v<=mid)  
        update(o*2,v,val);  
    else  
        update(o*2+1,v,val);  
    pushup(o);  
}  
int query(int x,int l, int r)  
{  
    if (tree[x].l >= l && tree[x].r <= r) {  
        return tree[x].val;  
    }  
    int mid = (tree[x].l + tree[x].r) / 2;  
    int ans = 0;  
    if (l <= mid) ans = max(ans, query(lson(x),l,r));  
    if (r > mid) ans = max(ans, query(rson(x),l,r));  
    return ans;  
}  
int Yougth(int u, int v) {  
    int tp1 = top[u], tp2 = top[v];  //tp1是指链头
    int ans = 0;  //结果归3
    while (tp1 != tp2) {  //如果是不同一条链呢
        //printf("YES\n");  
        if (dep[tp1] < dep[tp2]) {  //是u链头要比v的链头大，链头大的估计dep大
            swap(tp1, tp2);  
            swap(u, v);  
        }  
        ans = max(query(1,id[tp1], id[u]), ans);  //左区间大链头
        u = fa[tp1];  
        tp1 = top[u];  
    }  
    if (u == v) return ans;  
    if (dep[u] > dep[v]) swap(u, v);  
    ans = max(query(1,id[son[u]], id[v]), ans);  
    return ans;  
}  
void Clear(int n)  
{  
    for(int i=1;i<=n;i++)  
        v[i].clear();  
} 
int main()
{
    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            e[i].read();
            v[e[i].x].push_back(e[i].y);
            v[e[i].y].push_back(e[i].x);
        }
        num=0;
        dfs1(1,0,1);
        dfs2(1,1);
        for(int i=1;i<n;i++)
        {
            if(dep[e[i].x]<dep[e[i].y])swap(e[i].x,e[i].y);
            val[id[e[i].x]]=e[i].val;
        }
        build(1,num,1);
        char s[200];
        while(~scanf("%s",&s)&&s[0]!='D')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(s[0]=='Q')
                printf("%d\n",Yougth(x,y));
            if(s[0]=='C')
                update(1,id[e[x].x],y);
        }
        Clear(n);
    }
    return 0;
}