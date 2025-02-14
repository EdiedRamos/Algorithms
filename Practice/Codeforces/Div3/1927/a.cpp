// Make it White

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc, l, first, end;
	string s;
	cin >> tc;
	while (tc--)
	{
		cin >> l >> s;
		first = -1, end = 0;
		for (int i = 0; i < l; i++)
		{
			if (s[i] == 'B')
			{
				end = i;
				if (!~first)
				{
					first = i;
				}
			}
		}
		cout << end - first + 1 << endl;
	}
	return 0;
}
