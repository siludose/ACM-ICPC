#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn=50001;
const int maxt=1000001;
int n,t;
int use[maxn];
priority_queue<struct Cow> q;
struct Cow
{
	int start;
	int end;
	int order;
	bool operator <(const Cow &a)const
	{
		if(end==a.end)
			return start>a.start;
		return end>a.end;
	}
}cow[maxn];

bool cmp1(const Cow &a,const Cow &b)
{
	return a.start<b.start||(a.start==b.start&&a.end<b.end);
}
int solve()
{
	int num=1;
	q.push(cow[0]);
	use[cow[0].order]=1;
	for (int i=1;i<n;i++)
	{
		if (!q.empty()&&q.top().end<cow[i].start)
		{
			use[cow[i].order]=use[q.top().order];
			q.pop();
		}
		else
		{
			num++;
			use[cow[i].order]=num;
		}
		q.push(cow[i]);
	}
	cout<<num<<endl;
	while(!q.empty())
		q.pop();
	return 0;
}
int main()
{
	//freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>cow[i].start>>cow[i].end;
		cow[i].order=i;
	}
	sort(cow,cow+n,cmp1);
	solve();
	for (int i=0;i<n;i++)
	{
		cout<<use[i]<<endl;
	}
	return 0;
}

