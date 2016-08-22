#include<iostream>
using namespace std;
int main()
{
	char s[10000];
	char a[10000][100];
	int k=0,j=0;
	int tem=0; 
	int b;
	cin>>s;
	for(int i=0;s[i]!='\0';i++)
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
			a[k][j++]=s[i];
			tem=0;
		}
		else
		{
			if(tem==0)
			{
				tem=1;
				k++;
				continue;
			}
		}
	}
	cin>>b;

	return 0;
}