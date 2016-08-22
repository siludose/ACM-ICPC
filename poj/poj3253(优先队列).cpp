#include<iostream>
#include<queue>
using namespace std;
#define ll long long
priority_queue<int,vector<int>,greater<int> >q;
int num,n;
int main()
{
	freopen("input.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num);
			q.push(num);
		}
		ll res=0;
		while(q.size()>1)
		{
			ll a=q.top();q.pop();
			ll b=q.top();q.pop();
			
			res+=a+b;
			q.push(a+b);
		}
		while(!q.empty())
			q.pop();
		cout<<res<<endl;
	}
	return 0;
}
