#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#define rep(i,n) for(int i = 0;i < n; i++)  
using namespace std;  
const int size  = 200100,INF = 1<<30;  
int rk[size],sa[size],height[size],w[size],wa[size],res[size];  
void getSa (int len,int up) {  
    int *k = rk,*id = height,*r = res, *cnt = wa;  
    rep(i,up) cnt[i] = 0;  
    rep(i,len) cnt[k[i] = w[i]]++;  
    rep(i,up) cnt[i+1] += cnt[i];  
    for(int i = len - 1; i >= 0; i--) {  
        sa[--cnt[k[i]]] = i;  
    }  
    int d = 1,p = 0;  
    while(p < len){  
        for(int i = len - d; i < len; i++) id[p++] = i;  
        rep(i,len)  if(sa[i] >= d) id[p++] = sa[i] - d;  
        rep(i,len) r[i] = k[id[i]];  
        rep(i,up) cnt[i] = 0;  
        rep(i,len) cnt[r[i]]++;  
        rep(i,up) cnt[i+1] += cnt[i];  
        for(int i = len - 1; i >= 0; i--) {  
            sa[--cnt[r[i]]] = id[i];  
        }   
        swap(k,r);  
        p = 0;  
        k[sa[0]] = p++;  
        rep(i,len-1) {  
            if(sa[i]+d < len && sa[i+1]+d <len &&r[sa[i]] == r[sa[i+1]]&& r[sa[i]+d] == r[sa[i+1]+d])  
                k[sa[i+1]] = p - 1;  
            else k[sa[i+1]] = p++;  
        }  
        if(p >= len) return ;  
        d *= 2,up = p, p = 0;  
    }  
}  
void getHeight(int len) {  
    rep(i,len) rk[sa[i]] = i;  
    height[0] =  0;  
    for(int i = 0,p = 0; i < len - 1; i++) {  
        int j = sa[rk[i]-1];  
        while(i+p < len&& j+p < len&& w[i+p] == w[j+p]) {  
            p++;  
        }  
        height[rk[i]] = p;  
        p = max(0,p - 1);  
    }  
}  
int getSuffix(char s[]) {  
    int len = strlen(s),up = 0;   
    for(int i = 0; i < len; i++) {  
        w[i] = s[i];  
        up = max(up,w[i]);  
    }  
    w[len++] = 0;  
    getSa(len,up+1);  
    getHeight(len);  
    return len;  
}  
char s1[size],s2[size];
int len1,len2;
int main()
{
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        len1=strlen(s1);
        len2=strlen(s2);
        s1[len1]='$';
        for(int i=1;i<=len2;i++)
        {
            s1[i+len1]=s2[i-1];
        }
        getSuffix(s1);
        int ans=0;
        for(int i=1;i<len1+1+len2;i++)
        {
            if ((sa[i] < len1 && sa[i -1] > len1) || (sa[i] > len1 && sa[i -1] < len1))
                if(height[i]>ans)
                    ans=height[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
