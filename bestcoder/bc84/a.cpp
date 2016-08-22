#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cstring>
#define maxn 10000010
using namespace std;
int t;
char s[maxn];
int n[10];
bool flag;
int countt;
void fsc(char *ctr)
{
	int i=0;char c;
	while((c=getchar())!='\n'){
		ctr[i++]=c;n[c-'0']++;
	}
	ctr[i]='\0';
}

int main()
{
	scanf("%d",&t);
    getchar();
    while(t--)
    {
    	memset(n,0,sizeof(n));
        fsc(s);
        int marka,markb,markc=0,sum=0;       
		for(int i=1;i<=9;i++)
		{
			sum+=n[i];
		}
		if(sum<=1)
		{
			printf("Uncertain\n");continue;
		}
		for(int i=1;i<=9;i++)
		{
			if(n[i]>0)
			{
				marka=i;n[i]--;break;
			}
		}
		for(int i=0;i<=9;i++)
		{
			if(n[i]>0)
			{
				markb=i;n[i]--;break;
			}
		}
		if(marka+markb>=10)
		{
			for(int i=0;i<=9;i++)
			{
				if(n[i]>0)
				{
					markc=i;n[i]--;break;
				}
			}
			if(markc==0)
			{
				printf("%dn",marka+markb);
			}
			else
			{
				if(markc==9)
				{
					n[0]+=n[9];
					printf("1");
					for(int i=0;i<n[0]+1;i++)
					{
						putchar(0+'0');
					}
					printf("%d\n",(marka+markb)%10);
				}
				else
				{
					for(int i=9;i>=0;i--)
					{
						while(n[i]--)
						{
							putchar(i+'0');
						}
					}
					printf("%d%d\n",markc+1,(marka+markb)%10);
				}
			}
		}
        else
        {
        	for(int i=9;i>=0;i--)
			{
				while(n[i]--)
				{
					putchar(i+'0');
				}
			}
			printf("%d\n",marka+markb);
		}
    }
    return 0;
}
