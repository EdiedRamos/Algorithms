// * B. Triple

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, v, ans;
  cin >> t;
  while (t--)
  {
    cin >> n;
    map<int, int> cnt;
    ans = -1;
    while (n--)
    {
      cin >> v;
      cnt[v]++;
      if (cnt[v] > 2)
        ans = v;
    }
    cout << ans << endl;
  }
  return 0;
}