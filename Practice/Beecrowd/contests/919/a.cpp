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
  ull x, y;
  int d;
  while (cin >> x >> y && x || y)
  {
    d = 0;
    for (int i = 0; i < 64; i++)
    {
      if ((x & (1LL << i)) != (y & (1LL << i)))
      {
        d++;
      }
    }
    cout << d << endl;
  }
  return 0;
}