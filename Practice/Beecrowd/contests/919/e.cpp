#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef long long int lli;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull t, v, a;
  while (cin >> t && t)
  {
    a = 0;
    for (int i = 0; i < t; i++)
    {
      cin >> v;
      a ^= v;
    }
    cout << a << endl;
  }
  return 0;
}