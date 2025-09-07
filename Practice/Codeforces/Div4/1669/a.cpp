// * A. Division?

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, r;
  cin >> t;
  while (t--)
  {
    cin >> r;
    cout << "Division " << (r < 1400 ? 4 : r < 1600 ? 3
                                       : r < 1900   ? 2
                                                    : 1)
         << endl;
  }
  return 0;
}