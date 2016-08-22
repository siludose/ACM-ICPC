#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef pair<double,double> point;
const int M=100010;
point pnt[M];
#define X first
#define Y second
point bcenter( int n)
{
	point p,s;
	int i;
	double tp,area=0,tpx=0,tpy=0;
	p.X=pnt[0].X;p.Y=pnt[0].Y;
	for(i=1;i<=n;i++)
	{
		memcpy(&s,(i==n?pnt:pnt+i),sizeof(point));
		tp=(p.X*s.Y-p.Y*s.X);
		area+=tp/2.0;
		tpx+=(p.X+s.X)*tp;
		tpy+=(p.Y+s.Y)*tp;
		p.X=s.X;p.Y=s.Y;
	}
	s.X=tpx/( 6*area );
	s.Y=tpy/( 6*area );
	return s;
}
int main()
{
  int test,n,i;
  point zx;
  scanf("%d",&test);
  while(test--)
  {
    scanf("%d",&n);
    for(i=0;i<n;++i)
      scanf("%lf%lf",&pnt[i].X,&pnt[i].Y);
    zx=bcenter(n);
    printf("%.2lf %.2lf\n",zx.X,zx.Y);
  }
  return 0;
}