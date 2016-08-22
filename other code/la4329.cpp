#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define lowbit(x) ((x)&(-(x)))
using namespace std;

const int max_a=100000+1000;
const int max_num=20000+200;

typedef long long LL;

int a[20000+200];
LL cc[20000+200],dd[20000+200];
int n=max_a,C[max_a];

int sum(int x) {
	int ret = 0;
	while ( x>0 ) {
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d) {
	while(x <= n) {
		C[x] += d;
		x += lowbit(x);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;cin>>T;
	int num;
	for(int tt=1;tt<=T;tt++) {
		scanf("%d",&num);
		for(int i=0;i<num;i++)
			scanf("%d",&a[i]);


		memset(C,0,sizeof(C));
		for(int i=0;i<num;i++) {
			add(a[i],1);
			cc[i]=sum(a[i])-1;//cout<<cc[i]<<endl;
		}
		memset(C,0,sizeof(C));
		for(int i=num-1;i>=0;i--) {
			add(a[i],1);
			dd[i]=sum(a[i])-1;//cout<<cc[i]<<endl;
		}
		long long ans=0;
		for(int i=1;i<num-1;i++) {
			ans+=(cc[i])*(num-(1+i)-dd[i])+
				(i-cc[i])*(dd[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}