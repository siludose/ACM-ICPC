//#include<iostream>
//#include<queue>
////#pragma warning(disable:4996)
//using namespace std;
//const int maxs = 1000000+16;
//char s[maxs];
//int nextt[maxs];
//int main()
//{
//	//freopen("input.txt", "r", stdin);
//	while (scanf("%s",&s)&&s[0]!='.')
//	{
//		int size = strlen(s);
//		int j = 0;
//		for (int i = 1; i < size;i++)
//		{
//			if (s[i]==s[0])
//			{
//				nextt[j] = i;
//				j = i;
//			}
//		}
//
//		nextt[j] = size;
//		j = 0;
//		int i = 1,ans=1;
//		for (; i <size;i++)
//		{
//			if (s[i]==s[(nextt[j]!=1)?i%nextt[j]:j])
//			{
//				ans = (i+1) / nextt[j];
//			}
//			else
//			{
//				j = nextt[j];
//				i = nextt[j]-1;
//			}
//		}
//
//		cout << ans << endl;
//	}
//	return 0;
//}