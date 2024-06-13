// * A. Creating Words

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  string a, b;
  cin >> tc;
  while (tc--)
  {
    cin >> a >> b;
    swap(a[0], b[0]);
    cout << a << " " << b << endl;
  }
  return 0;
}