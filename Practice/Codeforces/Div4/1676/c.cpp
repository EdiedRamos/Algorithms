// * C. Most Similar Words

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int t, n, m, _min;

int diff(string a, string b)
{
  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    ans += abs(a[i] - b[i]);
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    vector<string> d(n);
    _min = 1e9;
    for (string &i : d)
      cin >> i;
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        _min = min(_min, diff(d[i], d[j]));
      }
    }
    cout << _min << endl;
  }
  return 0;
}