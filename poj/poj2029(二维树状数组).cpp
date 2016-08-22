#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int n,w,h,s,t;
#define maxn 200
int C[maxn][maxn];
int lowbit(int x)  
{  
    return x&(-1*x);  
}  
void Modify(int i, int j, int delta){  
          
    for(int x = i; x<=w; x += lowbit(x))  
        for(int y = j; y <=h; y += lowbit(y)){  
            C[x][y] += delta;     
   }  
}
int Sum(int i, int j){  
    int result = 0;  
    for(int x = i; x > 0; x -= lowbit(x)) {  
        for(int y = j; y > 0; y -= lowbit(y)) {  
            result += C[x][y];  
        }  
    }  
    return result;  
}  
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF&&n)
    {
    	memset(C,0,sizeof(C));
        scanf("%d%d",&w,&h);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&s,&t);
            Modify(s,t,1);
        }
        scanf("%d%d",&s,&t);
        int ans=-1;
        for(int i=s;i<=w;i++)
        {
            for(int j=t;j<=h;j++)
            {
                ans=max(ans,(Sum(i,j)-Sum(i,j-t)-Sum(i-s,j)+Sum(i-s,j-t)));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
