// * A. Minimize!

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc, a, b, c;
  cin >> tc;
  while (tc--)
  {
    cin >> a >> b;
    int ans = 1e9;
    for (int c = a; c <= b; c++)
    {
      int calc = (c - a) + (b - c);
      ans = min(ans, calc);
    }
    cout << ans << endl;
  }
  return 0;
}