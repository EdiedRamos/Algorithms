// * B. Equal Candies
// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, _min, ans;
  cin >> t;
  while (t--)
  {
    cin >> n;
    vector<int> d(n);
    _min = 1e9;
    ans = 0;
    for (int &i : d)
    {
      cin >> i;
      _min = min(_min, i);
    }
    for (int i : d)
    {
      ans += i - _min;
    }
    cout << ans << endl;
  }
  return 0;
}