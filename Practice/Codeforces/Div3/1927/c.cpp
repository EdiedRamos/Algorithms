// Choose the Different Ones!

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef pair<bool, bool> pbb;
typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc, n, m, k, xi, ca, cb, sr;
	bool can;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m >> k;
		map<int, pbb> fre;
		sr = 0;
		ca = cb = k >> 1;
		can = true;
		for (int i = 0; i < n; i++)
		{
			cin >> xi;
			fre[xi].first = true;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> xi;
			fre[xi].second = true;
		}
		for (int i = 1; i <= k && can; i++)
		{
			pbb ci = fre[i];
			bool hasFirst = ci.first;
			bool hasSecond = ci.second;
			if (!hasFirst && !hasSecond)
			{
				can = false;
			}
			if (hasFirst && hasSecond)
			{
				sr++;
			}
			else
			{
				if (hasFirst)
				{
					ca--;
				}
				else
				{
					cb--;
				}
			}
		}
		bool allUsed = ca > -1 && cb > -1 && ca + cb == sr;
		cout << (can && allUsed ? "YES" : "NO") << endl;
	}
	return 0;
}
