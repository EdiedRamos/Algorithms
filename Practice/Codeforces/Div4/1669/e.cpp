// * E. 2-Letter Strings

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  long long ans;
  string s;
  cin >> t;
  while (t--)
  {
    cin >> n;
    map<string, int> cnt;
    ans = 0;
    while (n--)
    {
      cin >> s;
      for (int i = 0; i < 2; i++)
      {
        for (char j = 'a'; j < 'l'; j++)
        {
          string x = "";
          if (!i)
          {
            if (s[1] == j)
              continue;
            x += s[i];
            x += j;
          }
          else
          {
            if (s[0] == j)
              continue;
            x += j;
            x += s[i];
          }
          ans += cnt[x];
        }
      }
      cnt[s]++;
    }
    cout << ans << endl;
  }
  return 0;
}