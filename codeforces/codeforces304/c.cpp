#include<iostream>
#include<queue>
//#pragma warning(disable:4996)
using namespace std;
int n,numa,numb,a,b;
queue<int> q1;
queue<int> q2;
int a1[30];
int a2[30];
int main()
{
	//freopen("input.txt", "r", stdin);
    cin>>n>>numa;
    for(int i=0;i<numa;i++)
    {
        scanf("%d",&a);
        q1.push(a);
		a1[i] = a;
    }
    cin>>numb;
    for(int i=0;i<numb;i++)
    {
        scanf("%d",&b);
        q2.push(b);
        a2[i]=b;
    }
    int ans=0;
	int res;
    while(!q1.empty()&&!q2.empty())
    {  
        a=q1.front();q1.pop();
        b=q2.front();q2.pop();
        if(a>b)
        {
            q1.push(b);
            q1.push(a);
        }
        else
        {
            q2.push(a);
            q2.push(b);
        }
        
        bool button=true;
        if(q2.size()==numb)
        {
            for(int i=0;i<numb;i++)
            {
                int temp=q2.front();q2.pop();             
                if(temp!=a2[i])
                {
                    button=false;
                }
                q2.push(temp);
            }
			for (int i = 0; i < numa; i++)
			{
				int temp = q1.front(); q1.pop();
				if (temp != a1[i])
				{
					button = false;
				}
				q1.push(temp);
			}
            if(button)
            {
                printf("%d",-1);
                return 0;
            }
        }
        ans++;
		if (ans > 10000)
		{
			printf("%d", -1);
			return 0;
		}
    }
	if (q1.empty())
	{
		res = 2;
	}
	else
	{
		res = 1;
	}
    printf("%d %d",ans,res);
    return 0;
}
