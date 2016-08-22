#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
#define maxn 1000010
int next[maxn],len;
char s[maxn];
void getnext(const char *s)  
{  
    int i = 0, j = -1;  
    next[0] = -1;  
    while(i != len)  
    {  
        if(j == -1 || s[i] == s[j])  
            next[++i] = ++j;  
        else  
            j = next[j];  
    }  
}
//int kmp(const char T[],const char P[],int next[])
//{
//    int n,m;
//    int i,q;
//    n=strlen(T);
//    m=strlen(P);
//    makenext(P,next);
//    for(i=0,q=0;i<n;i++)
//    {
//        while(q>0&&P[q]!=T[i])
//            q=next[q-1];
//        if(P[q]==T[i])
//        {
//            q++;
//        }
//        if(q==m)
//        {
//            printf("Pattern occurs with shift:%d\n",(i-m+1));
//        }
//    }
//} 
int main()
{
    scanf("%s",s);
    len=strlen(s);
    getnext(s);
    for(int i=0;i<=len;i++)
    {
        cout<<next[i]<<" ";
    }
    return 0;
}
