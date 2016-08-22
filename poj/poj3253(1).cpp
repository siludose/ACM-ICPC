#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxn=50001;
int main()
{
	_int64 N;
	_int64 L[maxn];
	_int64 spend=0;
	_int64 spend_temp=0;
	cin>>N;
	for (int i=0;i<N;i++)
	{
		cin>>L[i];
	}
	sort(L,L+N);
	int i=2;
	spend_temp=L[0]+L[1];
	while(i<N)
	{
		spend+=spend_temp;
		spend_temp+=L[i++];
	}
	spend+=spend_temp;
	cout<<spend;
	return 0;
}