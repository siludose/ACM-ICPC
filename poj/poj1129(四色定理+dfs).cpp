#include<iostream>
#include<string.h>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;
int n;
char s[30];
int du[30];
bool map[30][30];
int need[30],neednum;
int minans,ans;
bool flag;
bool used[30];
void dfs(int num)
{
    if(num>=neednum)
    {
        return;
    }
    dfs(num+1);
    for(int i=num+1;i<neednum;i++)
    {
        if(map[need[num]][need[i]]==0&&!used[need[i]]&&!used[need[num]])
        {
            map[need[num]][need[i]]=true;
			map[need[i]][need[num]]=true;
			used[need[i]] = true; used[need[num]] = true;
            ans--;
            if(minans>ans)
            {

                minans=ans;
            }
            dfs(num+1);
			used[need[i]] = 0; used[need[num]] = 0;
			map[need[num]][need[i]]=0;
			map[need[i]][need[num]]=0;
            ans++;
        }
    }
}
int main(int i)
{
	freopen("input.txt","r",stdin);
    while(~scanf("%d",&n)&&n)
    {
    	memset(map,0,sizeof(map));
		memset(du,0,sizeof(du));
		memset(need, 0, sizeof(need));
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            for(int k=2;k<len;k++)
            {
                map[s[0]-'A'][s[k]-'A']=true;
                du[s[0]-'A']++;
            }
        }
        int mark=0;ans=1;
        for(i=1;i<n;i++)
        {
            if(du[mark]<du[i])
            {
                mark=i;
                ans=du[mark];
            }
        }
		neednum = 0; flag = 0;
        for(i=0;i<n;i++)
        {
            if(map[mark][i]==true)
            {
                need[neednum++]=i;
            }
        }
        if(neednum>0)
        {
            minans=neednum;
			ans = neednum;
            dfs(0);
        }
		else
		{
			minans = 0;
		}
        if(minans<=0)
            printf("%d channels needed.\n",1);
        else
            printf("%d channel needed.\n",minans+1);
    }
    return 0;
}
