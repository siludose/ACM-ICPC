#include <iostream>
#include <vector>
using namespace std;
vector<pair<string,int>>boys;
int main()
{
	int n,k;
	string a;
	int b;
	for (int i=0;i<n;i++)
	{
		scanf("%s",a);
		scanf("%d",&b);
		boys.push_back(make_pair(a,b));
	}
	for (int i=0;i<n-1;i++)
	{
		vector<pair<string,int>>::iterator iter=boys.begin();
	}
	return 0;
}