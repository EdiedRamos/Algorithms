// * D. Colorful Stamp

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int t, n;
string s;

bool solve()
{
  int r = 0, b = 0;
  bool jw = 1;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'W')
    {
      if (!jw && (!r || !b))
        return 0;
    }
    else
    {
      jw = 0;
      if (i && s[i - 1] == 'W')
        r = b = 0;
      if (s[i] == 'R')
        r++;
      else
        b++;
    }
  }
  return r && b || jw;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--)
  {
    cin >> n >> s;
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}