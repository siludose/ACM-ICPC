#include<iostream>
#include<cstdio>
#include<math.h> 
using namespace std;
__int64 a;
int t;
const double eps = 1e-10;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d",&a);
//		if(a>=6&&(a%2==0))
//		{
//			printf("False\n");
//			continue;
//		}
//		if(a>=6&&(a%2==1))
//		{
//			printf("True\n");
//			continue;
//		}
//		if(a==0||a==4||a==5||a==3||a==1)
//		{
//			printf("True\n");
//			continue;
//		}
//		else
//		{
//			printf("False\n");
//		}	
		if(a%2==1)
		{
			printf("True\n");
			continue;
		}
//		cout<<sqrt(a*1.0)<<endl;
//		cout<<(double)((int)sqrt(a*1.0))<<endl;
		if(sqrt(a*1.0)-(double)((int)sqrt(a*1.0))<eps)
		{
			printf("True\n");
			continue;
		}
		if(a%8!=0)
		{
			printf("False\n");
			continue;
		}
		a++;
		if(sqrt(a*1.0)-(double)((int)sqrt(a*1.0))<eps)
		{
			printf("True\n");
		}
		else
		{
			printf("False\n");
		}
//		cout<<sqrt((double)10000000*10000000*1.0)<<endl;
	}
	return 0;
}
