// * C. Good Prefixes

/*
  [1, 6, 3, 2] Just 6 can be the sum of all other elements.
  [1, 7, 3, 2] Just 7 can be the sum of all other elements.
  In other words just the greatest number can be the sum of all other elements. 😋
*/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef long long int big;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc, n, ans;
  big curMax;
  cin >> tc;
  while (tc--)
  {
    cin >> n;
    ans = 0;
    vector<big> vi(n);
    for (big &i : vi)
      cin >> i;
    big sum = 0;
    curMax = 0;
    for (big i : vi)
    {
      sum += i;
      curMax = max(curMax, i);
      if (sum - curMax == curMax)
        ans++;
    }
    cout << ans << endl;
  }
  return 0;
}