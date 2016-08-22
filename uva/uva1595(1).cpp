#include<iostream>
#include<set>
#include<utility>
using namespace std;
set<pair<int,int>>set1;
pair<int,int> pair_1;
int main()
{
	int m,n;
	int a,b;
	int mid;
	bool bool1=false;
	cin>>m;
	while (m--)
	{
		cin>>n;
		while(n--)
		{
			cin>>a>>b;
			pair_1.first=a;
			pair_1.second=b;
			set1.insert(pair_1);

		}
		set<pair<int,int>>::iterator iter1=set1.begin();

		for(;iter1!=set1.end();iter1++)
		{
			cout<<iter1->first<<"  "<<iter1->second<<endl;
		}
		
		
		
		
		
		mid=iter1->first;
		/*set<pair<int,int>>::iterator iter2=set1.end();*/
		/*mid+=iter2->second;*/		
		
		/*
		while(iter1->first>iter2->first)
		{
			if ((iter1->first+iter2->first)==mid)
			{
				if (iter1->second==iter2->second)
				{
					iter1++;
					iter2--;
					continue;
				}
				else
				{
					bool1=true;
					break;
				}
			} 
			else
			{
				bool1=true;
			}
		
		}
		if (bool1==true)
		{
			cout<<"NO"<<endl;
		} 
		else
		{
			cout<<"YES"<<endl;
		}*/
	}
	return 0;
}