// * C. Odd/Even Increments

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, v;
  cin >> t;
  while (t--)
  {
    cin >> n;
    set<int> odd, even;
    for (int i = 0; i < n; i++)
    {
      cin >> v;
      if (i & 1)
        even.insert(v & 1);
      else
        odd.insert(v & 1);
    }
    cout << (even.size() == 1 && odd.size() == 1 ? "YES" : "NO") << endl;
  }
  return 0;
}