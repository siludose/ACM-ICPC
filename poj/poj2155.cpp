#include <iostream>
using namespace std;
const int MAX_N=1024;
int c[MAX_N][MAX_N];
int main()
{
	int X,N,T;
	char ch;
	int x1,x2,y1,y2;
	cin>>X;
	while(X--)
	{
		memset(c,0,sizeof(c));
		cin>>N>>T;
		while(T--)
		{
			scanf(" %c",c);
			if (ch=='C')
			{
				scanf("%d %d %d %d",&x1,&x2,&y1,&y2);

			}
		}
	}
	return 0;
}