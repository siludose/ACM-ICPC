#include <iostream>
using namespace std;
int d[7];
int ans;
int now;
int allow_size;
void set_allow_size(int i)
{
	if (i>3)
	{
		allow_size=6-i;
	}
	else if (i>=2)
	{
		allow_size=i-1;
	}
	else
	{
		allow_size=6;
	}
}
void add(int i)
{
	if (d[i]*i*i>36-now)
	{
		d[i]=(d[i]*i*i-(36-now))/(i*i);
		now=0;
		ans++;
		allow_size=6;
	}
	else if (d[i]*i*i==36-now)
	{
		d[i]=0;
		now=0;
		ans++;
		allow_size=6;
	}
	else
	{
		now+=d[i]*i*i;
		d[i]=0;
		set_allow_size(i);
		if (allow_size!=6)
		{
			add(allow_size);
		}
	}	
}
void fill(int i)
{
	if (i==6)
	{
		ans+=d[i];
		d[i]=0;
	}
	else if (i>3)
	{
		d[i]--;
		now=d[i]*i*i;
		set_allow_size(i);
		add(allow_size);
	}
	else
	{
		ans+=(d[i]*i*i)/36;
		now+=(d[i]*i*i)%36;
		d[i]=0;
		if (i==1)
		{
			return;
		}
		if (now!=0)
		{
			set_allow_size(i);
			add(allow_size);
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	while(1)
	{
		cin>>d[1]>>d[2]>>d[3]>>d[4]>>d[5]>>d[6];
		ans=0;
		now=0;
		allow_size=6;
		if (!(d[1]||d[2]||d[3]||d[4]||d[5]||d[6]))
		{
			break;
		}
		while(1)
		{
			if (now!=0)
			{
				ans++;
				now=0;
			}
			int i;
			for (i=6;i>0;i--)			
				if (d[i]!=0)			
					break;			
			if (i==0)			
				break;
			allow_size=6;
			fill(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}