#include<iostream>
using namespace std;
#define _int64 long long
void mul(__int64 a[2][2],__int64 b[2][2])
{

	_int64 lt,rt,bl,br;

	lt=a[0][0]*b[0][0]+a[0][1]*b[1][0];
 bl=rt=a[0][0]*b[0][1]+a[0][1]*b[1][1];	
	br=a[1][0]*b[0][1]+a[1][1]*b[1][1];

	a[0][0] = lt; a[0][1] = rt;
	a[1][0] = bl; a[1][1] = br;
}

void fib(_int64 f[2][2],int n)
{
	if(n==1||n==0)
		return;
	_int64 m[2][2]={{1,1},{1,0}};
	
	fib(f,n>>1);
	mul(f,f);
	
	if(n%2)
		mul(f,m);
}
int main()
{
	for (int i = 0; i < 100;i++)
	{
		_int64 f[2][2] = { { 1,1 },{ 1,0 } };
		fib(f, i);
		printf("Fibonacci(%d)=%lld\n", i, f[0][1]);
	}
	return 0;
}
