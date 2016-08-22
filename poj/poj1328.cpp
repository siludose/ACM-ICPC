#include<iostream>
#include<string.h>
#include<algorithm>
#include <math.h>
const int maxn=1001;
using namespace std; 
int n;
int d;
double max_x,min_x;
struct Islands
{
	double x;
	double y;
}point[maxn];
struct Center//记录每个岛屿允许的雷达的横坐标范围
{
	double min_x;
	double max_x;
}center[maxn];
bool together(double* max_x ,double* min_x,double other_min_x,double other_max_x)//查看两个岛屿与否能使用同一个雷达
{
	if (*max_x>other_max_x)
	{
		*max_x=other_max_x;
	}
	if (*min_x<other_min_x)
	{
		*min_x=other_min_x;
	}
	if (*max_x<*min_x)	
		return false;
	else
		return true;

}
int solve()
{
	int ans=0;
	int i=0;
	int j;
	for (int i=0;i<n;i++)
	{
		if (point[i].y>d)
		{
			return -1;
		}
	}
	while(i<n)
	{
		j=i+1;
		max_x=center[i].max_x;
		min_x=center[i].min_x;
		while(j<n)
		{//这个雷达可以服务的岛屿
			if(together(&max_x,&min_x,center[j].min_x,center[j].max_x))
				j++;
			else
			{
				break;
			}
		}
		i=j;
		ans++;
		if (i==n)
		{
			break;//循环出口
		}
	}
	return ans;
}
void getcenter(double x,double y,int i)
{
	double r;
	r=sqrt(d*d-y*y);
	center[i].min_x=x-r;
	center[i].max_x=x+r;
}

bool cmp(const Islands &a,const Islands &b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int main()
{
	int time=1;
	
	while(cin>>n>>d&&(n||d))
	{
		for (int i=0;i<n;i++)
		{
			cin>>point[i].x>>point[i].y;
		}

		sort(point,point+n,cmp);

		for(int i=0;i<n;i++)
		{
			getcenter(point[i].x,point[i].y,i);
		}
		cout<<"Case "<<time++<<": "<<solve()<<endl;
	}
	return 0;
}
