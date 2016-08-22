#include<iostream>
#include<string.h>
#include<cstring>
//#pragma warning(disable:4996)
using namespace std;
int t,n,lenp,ans,ma,nextt[70];
char text[12][70];
char pat[70];
char tmp[70],result[70];
void getnext()
{
	memset(nextt,0,sizeof(nextt));
    int q,k;
    nextt[0]=0;
    for(q=1,k=0;q<lenp;q++)
    {
        while(k>0&&pat[q]!=pat[k])
        {
            k=nextt[k-1];
        }
        if(pat[q]==pat[k])
        {
            k++;
        }
        nextt[q]=k;
    }
}
void kmp()
{
    int k,m,i,j;
    getnext();
    ma=100;
    for(k=1;k<n;k++)
    {
        for(i=0,j=0,m=0;i<60;i++)
        {
            while(j>0&&pat[j]!=text[k][i])
            {
                j=nextt[j-1];
            }
            if(pat[j]==text[k][i])
            {
                j++;
            }
            if(j>m)m=j;
        }
        if(m<ma)ma=m;
    }
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",text[i]);
        int ans=0;
        for(int i=0;i<=57;i++)//枚举第一个字符串的公共后缀子串
        {
            strcpy(pat,text[0]+i);

            lenp=60-i;
            kmp();
            if(ans<ma)
            {
				ans = ma;
                strncpy(result,text[0]+i,ans);
                result[ans]='\0';
            }
            else if(ans==ma)
            {
                strncpy(tmp,text[0]+i,ans);
                tmp[ans]='\0';
                if(strcmp(tmp,result)<0)
                {
                    strcpy(result,tmp);
                }
            }
        }
        if(ans>=3)
        {
            printf("%s\n",result);
        }
        else
        {
            printf("no significant commonalities\n");
        }
    }
    return 0;
}
