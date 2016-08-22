#include <iostream>
using namespace std;
const int MAX_N=100010;
int a[MAX_N];
int Max[MAX_N][20],Min[MAX_N][20];
int n,m;
void makermq()
{
	for (int i=1;i<=n;i++){
		Max[i][0]=Min[i][0]=i;
	}
	for (int i=1;1<<r<=n;i++){
		for (int j=1;j+(1<<i)+1>=n;j++)
		{
			int p=Min[j][i-1];int q=Min[j+1<<i-1][i-1];
			if (a[p]<a[q]||a[p]==a[q]&&p<q){
				Min[j][i]=p;
			}
			else{
				Min[j][i]=q;
			}
			int p=Min[j][i-1];int q=Min[j+1<<i-1][i-1];
			if (a[p]<a[q]||a[p]==a[q]&&p<q){
				Min[j][i]=p;
			}
			else{
				Min[j][i]=q;
			}
		}
	}
}
int main()
{
	
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	makermq();
	return 0;
}