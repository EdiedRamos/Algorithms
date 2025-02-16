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
  ull a, b, c;
  while (cin >> a >> b)
  {
    c = a ^ b;
    cout << c << endl;
  }
  return 0;
}