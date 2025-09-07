// * H. Maximal AND

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, k, ans, turn_on;
  cin >> t;
  while (t--)
  {
    ans = 0;
    cin >> n >> k;
    vector<int> d(n);
    for (int &i : d)
      cin >> i;
    for (int shift = 30; shift >= 0; shift--)
    {
      turn_on = 0;
      for (int i : d)
      {
        if (!(i & (1 << shift)))
          turn_on++;
      }
      if (turn_on <= k)
      {
        ans += 1 << shift;
        k -= turn_on;
      }
    }
    cout << ans << endl;
  }
  return 0;
}