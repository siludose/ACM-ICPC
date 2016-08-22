#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int t,m,n,k,temp,q,i;
char qc[2];
multiset<int> table;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&m,&n,&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d",&temp);
			table.insert(temp);
		}
		scanf("%d",&q);
		while(q--)
		{
			cin>>qc>>qi;
			if(qc[0]=='I')
			{
				table.insert(qi);
			}
			else if(qc[0]=='R')
			{
//				set<int>::iterator iter;
//				if((iter=table.find(qi))!=table.end())
//				{
//					table.erase()
//				}
				table.erase(qi);
			}
			else
			{
				set<int>::iterator iter;
				if((iter=table.find(qi))!=table.end())
				{
					int 
				}
			}
		}
	}
	return 0;
}
