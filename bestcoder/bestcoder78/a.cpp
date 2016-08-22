#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int t;
__int64 a[5];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<4;i++)
        {
            scanf("%I64d",&a[i]);
        }
        sort(a,a+4);
        for(int i=0;i<4;i++)
        {
        	cout<<a[i]<<endl;
		}
        if(a[0]<a[1]+a[2]+a[3])
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}
