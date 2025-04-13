#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc, n, m, l, r;
  cin >> tc;
  while (tc--)
  {
    cin >> n >> m >> l >> r;
    int optionL = 0, optionR = 0;
    while (m > 0 && optionL > l)
    {
      optionL--;
      m--;
    }
    while (m > 0 && optionR < r)
    {
      optionR++;
      m--;
    }
    cout << optionL << " " << optionR << endl;
  }
  return 0;
}