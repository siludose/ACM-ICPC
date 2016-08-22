#include <iostream>
#include<queue>
using namespace std;
const int MAX_N=100005;
int n,s;
int x[MAX_N];

int solve()
{
	//int res=n+1;
	//int s=0,t=0,sum=0;
	//for (;;){
	//	while(t<n&&sum<S){
	//		sum+=a[t++];
	//	}
	//	if(sum<S)break;
	//	res=min(res,t-s);
	//	sum-=a[s++];
	//}
	//if(res>n)return 0;
	//else return res;
	queue<int> q;
	int i=0;
	int sum=0;
	int sum_i=0;
	q.push(x[i]);
	sum+=x[i];
	sum_i++;
	int min_sum_i=0x7f7f7f7f;
	while(i<n)
	{
		while(sum<s&&i<n)
		{
			i++;
			q.push(x[i]);
			sum+=x[i];
			sum_i++;
		}
		while (sum>=s&&i<n)
		{
			min_sum_i=min(min_sum_i,sum_i);
			sum-=q.front();
			sum_i--;
			q.pop();
		}
	}
	if(min_sum_i>n)
		return 0;
	return min_sum_i;
}
int main()
{
	//freopen("input.txt","r",stdin);
	int num;
	cin>>num;
	while(num--)
	{
		cin>>n>>s;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
		cout<<solve()<<endl;
	}
	return 0;
}
//int solve()
	//{

	//}