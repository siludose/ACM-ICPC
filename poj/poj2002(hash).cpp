#include<iostream>
#include<vector>
using namespace std;
int n,a,b,c,d;
const int prime=14997*5;
struct Node
{
    int x;int y;
};
vector<Node>hash[prime];
struct Node node[1010];
void init()
{
	for(int i=0;i<prime;i++)
	{
		hash[i].clear();
	}
}
void insert(int i)
{
    int key=(node[i].x*node[i].x+node[i].y*node[i].y)%prime;
    hash[key].push_back(node[i]);
}
bool find(int a,int b)
{
    int key=(a*a+b*b)%prime;
    if(!hash[key].empty())
    {
        for(int i=0;i<hash[key].size();i++)
        {
            if(a==hash[key][i].x&&b==hash[key][i].y)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
	//freopen("input.txt","r",stdin);
    while(~scanf("%d",&n))
    {
    	if(n==0)
    	{
    		break;
		}
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&node[i].x,&node[i].y);
            insert(i);
        }
        long long res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i!=j)
                {
                    a=node[i].x+(node[i].y-node[j].y);
                    b=node[i].y-(node[i].x-node[j].x);
                    c=node[j].x+(node[i].y-node[j].y);
                    d=node[j].y-(node[i].x-node[j].x);
                    if(find(a,b)&&find(c,d))
                        res++;

                    a=node[i].x-(node[i].y-node[j].y);
                    b=node[i].y+(node[i].x-node[j].x);
                    c=node[j].x-(node[i].y-node[j].y);
                    d=node[j].y+(node[i].x-node[j].x);
                    if(find(a,b)&&find(c,d))
                        res++;
                }
            }
        }
        cout<<res/4<<endl;
        init();
    }
    return 0;
}
