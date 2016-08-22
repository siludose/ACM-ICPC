#include<iostream>
#include<cstdio>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
#define maxn 1000100
int n,len;
char s[maxn];
char ss[maxn];
bool use[maxn];
bool xiaoshu;
int index; bool f; int nnnn;
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		memset(use,1,sizeof(use));
		len=strlen(s);xiaoshu=false;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='0')
				use[i]=false;
			else
				break;
		}
		for(int i=0;i<len;i++)
		{
			if(s[i]=='.')
			{
				xiaoshu=1;
				index=i;
				break;
			}			
		}
		f = true;
		if (xiaoshu)
		{
			if (index == len - 1)//判断小数点是不是在最后
			{
				xiaoshu = 0; use[index] = false;
			}
			else//小数点后除0
			{
				int temp = index;
				for (int i = index + 1; i < len; i++) {
					if (s[i] != '0') {
						temp = i;
					}
				}
				for (int i = temp + 1; i < len; i++) {
					use[i] = false;
				}
				if (!use[index + 1])
					use[index] = false;
			}
			f = false; nnnn = 0;
			for (int i = 0; i < index; i++)
			{
				if(use[i])
					f = true;
			}
			if (!f)
			{
				use[index] = false;
				for (int i = index + 1; i < len; i++)
					if (s[i] == '0')
					{
						use[i] = false; nnnn++;
					}
					else
						break;
			}
		}
		int num=0;xiaoshu=0;
		for(int i=0;i<len;i++)
		{
			if(use[i]){
				ss[num++]=s[i];
				if(ss[num-1]=='.'){
					xiaoshu=1;index=num-1;
				}
			}
		}
		memset(use, 1, sizeof(use));
		len = strlen(ss);
		int countt=0;
		if(!xiaoshu&&f)
		{
			for(int i=len-1;i>0;i--)
			{
				if(ss[i]=='0'){
					use[i]=0;
				}
				else
					break;	
			}
			for(int i=0;i<len;i++){
				if (!use[i])continue;
				printf("%c",ss[i]);
				if(i==0&&use[1]&&len!=1)
					printf(".");
			}
			if (len != 1)
				printf("E%d\n", len - 1);
			else
				printf("\n");
		}
		else if (len == 0)
		{
			printf("0\n");
		}
		else
		{
			if (!f)
			{
				for (int i = 0; i < len; i++) {
					printf("%c", ss[i]);
					if (i == 0&&len!=1)
						printf(".");
				}
				printf("E%d\n",-nnnn-1);
			}
			else
			{
				for(int i=0;i<len;i++){
					if(i==index)continue;
					printf("%c",ss[i]);
					if(i==0)
						printf(".");
				}
				if (index == 1)continue;
				printf("E%d\n",index-1);
			}
		}
	}

	return 0; 
}
