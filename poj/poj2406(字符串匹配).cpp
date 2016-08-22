#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstring>
#include<string>
#define maxn 1000000
using namespace std;
char a[maxn];
int next[maxn];
int len;
//void makenext(const char P[],int next[])
//{
//    int q,k;
//    int m=strlen(P);
//    next[0]=0;
//    for(q=1,k=0;q<m;q++)
//    {
//        while(k>0&&P[q]!=P[k])
//        {
//            k=next[k-1];
//        }
//        if(P[q]==P[k])
//        {
//            k++;
//        }
//        next[q]=k;
//    }
//}
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
int main()
{
	int length,add;
	int ans;
	while(~scanf("%s",a))
	{
		
		len=strlen(a);
		if(a[0]=='.')
		{
			break;
		}
		getnext(a);
		ans=0;
		if(len%(len-next[len])==0)
			printf("%d\n",len/(len-next[len]));
		else
			printf("%d\n",1);
	}
	return 0;
}
