#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef pair<double,double> point;//������ʽ������double...
typedef pair<point,point> line;
const double eps=1e-8;
#define X first
#define Y second
int sgn(double v){return v<-eps?-1:fabs(v)>eps;}
point basp;
double dis2(point a,point b){return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);}//�Ƚ��ã��¾��ȶ�ʧ�������
double dist(point a,point b){return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));}//���㳤����
double xmult(point p1,point p2,point p0)//(p0->p1)*(p0->p2)���
{
    return (p1.X-p0.X)*(p2.Y-p0.Y)-(p2.X-p0.X)*(p1.Y-p0.Y);
}

double dot(point p1,point p2,point p0)//(p0->p1).(p0->p2)���
{
    return (p1.X-p0.X)*(p2.X-p0.X)+(p1.Y-p0.Y)*(p2.Y-p0.Y);
}
bool CmpBYAngle(const point& a,const point& b)//����������ʱ������ڣ������С���ߣ��ذѼ��������ټ򻯴���
{
    int res = xmult(basp,a,b);
    return res > 0 || (!res && dis2(a,basp)<dis2(b,basp) );
}

bool dots_inline(point p1,point p2,point p3)
{
    return sgn(xmult(p1,p2,p3))==0;
}

bool same_side(point p1,point p2,line l)
{
    return xmult(l.X,p1,l.Y)*xmult(l.X,p2,l.Y)>eps;
}

bool dot_online_in(point p,line l)
{
    return !sgn(xmult(p,l.X,l.Y)) && (l.X.X-p.X)*(l.Y.X-p.X)<eps && (l.X.Y-p.Y)*(l.Y.Y-p.Y)<eps;
}

bool intersect_in1(line u,line v)//�ж��߶μ��ཻ��ϵ��
{
    if (!dots_inline(u.X,u.Y,v.X)||!dots_inline(u.X,u.Y,v.Y))
        return !same_side(u.X,u.Y,v)&&!same_side(v.X,v.Y,u);
    return dot_online_in(u.X,v)||dot_online_in(u.Y,v)||dot_online_in(v.X,u)||dot_online_in(v.Y,u);
}

bool intersect_in2(line u,line v)//�ж��߶μ��ཻ��ϵ�ģ����迼�Ƕ˵�������
{
	return (!same_side(u.X,u.Y,v))&&(!same_side(v.X,v.Y,u));
}

point inter(line u,line v)
{
	double k=xmult(v.X,v.Y,u.X)/xmult(v.X,v.Y,u.Y);
	return make_pair(u.X.X+(u.Y.X-u.X.X)*k,u.X.Y+(u.Y.Y-u.X.Y)*k);
}

double rotating_calipers(point *p,int n){//͹������ת���ǣ��˴�������Ӿ���
    int R=1,U=1,L;
    double ans = 10000000000000;
    p[n]=p[0];
    for(int i=0;i<n;i++){
        while(sgn(xmult(p[i+1],p[U+1],p[i])-xmult(p[i+1],p[U],p[i]))<=0) U=(U+1)%n;//������һ��
        while(sgn(dot(p[i+1],p[R+1],p[i])-dot(p[i+1],p[R],p[i]))>0) R=(R+1)%n;//����һ��
        if(i==0)L=R;
        while(sgn(dot(p[i+1],p[L+1],p[i])-dot(p[i+1],p[L],p[i]))<=0) L=(L+1)%n;//����һ��
        double d=dist(p[i],p[i+1])*dist(p[i],p[i+1]);
        double area=fabs(xmult(p[i+1],p[U],p[i]))*fabs(dot(p[i+1],p[R],p[i])-dot(p[i+1],p[L],p[i]))/d;//�����
        if(area<ans) ans = area;
    }
    return ans;
}
int main()
{
	int n,i,j,cnt;
	while(scanf("%d",&n) && n)//������Ŀ��������0���������ļ�����
	{
		line l[105];
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&l[i].X.X,&l[i].X.Y,&l[i].Y.X,&l[i].Y.Y);
		for(i=0,cnt=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(intersect_in1(l[i], l[j]))
					cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}