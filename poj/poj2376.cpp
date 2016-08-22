#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=25005;
pair<int,int>time[maxn];
int n,t;
bool is_greater(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.first<b.first||(a.first==b.first&&a.second>b.second);
}
int solve()
{
	int used_cows=0;
	int end=0;
	int index=0;
	while(end<t)
	{
		int begin=end+1;
		for(int i=index;i<n;i++)
		{
			if(time[i].first<=begin)
			{
				if(time[i].second>=begin)
				{
					end=max(end,time[i].second);
				}		
			}
			else
			{
				index=i;
				break;
			}
		}
		if(begin>end)
		{
			return -1;
		}
		else
		{
			used_cows++;
		}
	}
	return used_cows;
}
int main(void)
{
	scanf("%d%d",&n,&t);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&time[i].first,&time[i].second);
	}
	sort(time,time+n,is_greater);
	cout<<solve()<<endl;
}
