#include<iostream>
#include<string.h>
#include<cstring>
#include<cstdio>
using namespace std;
void makenext(const char p[],int next[])
{
    int q,k;
    int m=strlen(P);
    next[0]=0;
    for(q=1,k=0;q<m;q++)
    {
        while(k>0&&P[q]!=P[k])
        {
            k=next[k-1];
        }
        if(P[q]==P[k])
        {
            k++;
        }
        next[q]=k;
    }
}
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
int kmp(const char T[],const char P[],int next[])
{
    int n,m;
    int i,q;
    n=strlen(T);
    m=strlen(P);
    makenext(P,next);
    for(i=0,q=0;i<n;i++)
    {
        while(q>0&&P[q]!=T[i])
            q=next[q-1];
        if(P[q]==T[i])
        {
            q++;
        }
        if(q==m)
        {
            printf("Pattern occurs with shift:%d\n",(i-m+1));
        }
    }
}
int main()
{
    int i;
    int next[20]={0};
    char T[]="ababxbababcadfdsss";
    char P[]="abcdabd";
    kmp(T,P,next);
    for(i=0;i<strlen(P);i++)
    {
        printf("%d ",next[i]);

    printf("\n");
    return 0;
}