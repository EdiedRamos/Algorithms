// Following the String

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc, n, t;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		string ans = "";
		char cur = 'a';
		int fre[26];
		memset(fre, 0, sizeof fre);
		while (n--)
		{
			cin >> t;
			if (t == 0)
			{
				ans += cur;
				fre[cur - 'a']++;
				cur++;
			}
			else
			{
				for (int i = 0; i < 26; i++)
				{
					if (fre[i] == t)
					{
						char cc = 'a' + i;
						ans += cc;
						fre[i]++;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
