// * F. Eating Candies

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, l, r, ans, cnt, x, y;
  cin >> t;
  while (t--)
  {
    cin >> n;
    vector<int> d(n);
    ans = cnt = x = y = 0;
    for (int &i : d)
      cin >> i;
    l = 0, r = n - 1;
    while (l <= r)
    {
      if (x == y)
        ans = max(ans, cnt);
      if (x < y)
      {
        x += d[l];
        l++;
      }
      else
      {
        y += d[r];
        r--;
      }
      cnt++;
    }
    if (x == y)
      ans = max(ans, cnt);
    cout << ans << endl;
  }
  return 0;
}