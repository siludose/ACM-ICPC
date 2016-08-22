#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100000 + 16
typedef long long LL;

LL bit0[MAX_N], bit1[MAX_N];	// ˫BITʵ��O(logn)����ӷ�
int N, X[MAX_N], Y[MAX_N];
vector<int> line[MAX_N];	// ÿ�����ӹ��ɵ�һ����ˮƽ�ߣ�y������Ϊ�±�
bool visited[MAX_N];		// �Ƿ��Ѿ������


// ���sum{a[t], 0 <= t <= i}
LL sum(LL *b, int i)
{
	int s = 0;
	while (i > 0) 
	{
		s += b[i];
		i -= (i & -i);
	}
	return s;
}

// ���a[from, to)
LL sum(LL* bit, int from, int to)
{
	return sum(bit, to - 1) - sum(bit, from - 1);
}

// ִ�� a[i] += v
void add(LL *b, int i, LL v)
{
	while (i <= MAX_N)
	{
		b[i] += v;
		i += (i & -i);
	}
}
// ����bit����

// ˫BIT

//[0,n]
LL sum(int i)
{
	return sum(bit1, i) * i + sum(bit0, i);
}

//(from, to]
LL sum(int from, int to)
{
	return sum(to) - sum(from);
}

// [from, to]
void add(int from, int to, LL x)
{
	add(bit0, from, -x * (from - 1));
	add(bit1, from, x);
	add(bit0, to, x * to);
	add(bit1, to, -x);
}

// ѹ�����꣬�������ֵ��ɡ����ǵڼ���ֵ��������һ���м�������
// xΪ�������飬����ΪN
int compress(int *p)
{
	vector<int> ps(N);

	for (int i = 0; i < N; ++i)
	{
		ps[i] = p[i];
	}

	sort(ps.begin(), ps.end());
	ps.erase(unique(ps.begin(), ps.end()), ps.end());
	for (int i = 0; i < N; ++i)
	{
		p[i] = 1 + distance(ps.begin(), lower_bound(ps.begin(), ps.end(), p[i]));	// �˴���1Ϊ�˷�ֹ i += (i & -i); ��ԶΪ0
	}
	return ps.size();
}


int main()
{scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", X + i, Y + i);
	}
	int w = compress(X);
	int h = compress(Y);

	for (int i = 0; i < N; ++i)
	{
		line[Y[i]].push_back(X[i]);	// һ����ɨ����
	}

	LL result = N;
	for (int y = 1; y <= h; ++y)
	{
		// ��ÿ��ɨ���ߣ���������հ׵�ĸ���
		vector<int>& xs = line[y];	// ������Ϊy����Щ��ĺ����꣬һ��ɨ����
		sort(xs.begin(), xs.end());

		for (vector<int>::iterator i = xs.begin(); i != xs.end(); ++i)
		{
			int x = *i;
			LL s = sum(x - 1, x);	// ������Ϊx�Ŀհ׵����

			if (visited[x])
			{
				result += s;		// ����ҪȾɫ�����ص�
			}
			else
			{
				visited[x] = true;
			}
			add(bit0, x, -s);		// ��ͬ��add(x, x, -s);����count[x] -= s������һ����λ������Ϊ�´�ͳ����׼��
			if (i + 1 != xs.end())
			{
				// ����һ���ڵ�֮��հ׵�ĸ���
				// ��������֧�ϲ��������� add(x + 1, next_x - 1, 1);����˼
				if (x + 1 < *(i + 1) - 1)			// ��һ������
				{
					add(x + 1, *(i + 1) - 1, 1);	// �����˿հ�
				}
				else if (x + 1 == *(i + 1) - 1)
				{
					add(bit0, x + 1, 1);			// �����˿հ�,��ʱ��ͬ��add(x + 1, x + 1, 1);
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}
