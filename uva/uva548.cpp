#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxv=1000+10;
int n;
int in_order[maxv];
int post_order[maxv];
int array[maxv];
int array_left[maxv];
int array_right[maxv];
int best_num;best_sum;
int left,right;
bool read_input(int *a)
{
	string line;
	if(!getline(cin,line))return false;
	stringstream ss(line);
	n=0;
	int x;
	while(ss>>x) a[n++]=x;
	return n>0;
}
int build(int L1,int,R1,int mid)
{
	int root=post_order[n-1];
	while(in_order[mid]!=root)
	{
		mid++;
	}
	build(L1,mid-1,)


}
int bdf()
{

}
int main()
{
	while(read_input(in_order))
	{
		read_input(post_order);
		left=0;
		right=0;
		build();
		bdf();
		cout<<best_sum;

	}
	return 0;
}