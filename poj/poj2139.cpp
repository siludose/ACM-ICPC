#include <iostream>
#include <string.h>
using namespace std;
const int maxn=301;
int d[maxn][maxn];
int cow[maxn];
int n,m;
void floyd()
{
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
}
int main()
{
	//freopen("input.txt","r",stdin);
	memset(d,0x3f,sizeof(d));
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		d[i][i] = 0;
	}
	while (m--)
	{
		int k;
		cin>>k;
		for (int j=0;j<k;j++)
		{
			cin>>cow[j];
			cow[j]--;
		}
		for(int i=0;i<k;i++)
			for (int j=i+1;j<k;j++)
			{			
					d[cow[i]][cow[j]]=1;
					d[cow[j]][cow[i]]=1;			
			}
	}
	floyd();
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
		{
			sum += d[i][j];
		}
		ans = min(ans, sum);
	}
	cout << 100 * ans / (n- 1) << endl;
	return 0;
}