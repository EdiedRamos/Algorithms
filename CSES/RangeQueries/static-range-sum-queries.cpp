// * Coder: EdiedRamos
// * Problem link: https://cses.fi/problemset/task/1646

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef long long ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q, a, b;

  cin >> n >> q;

  ll data[n + 1], pre[n + 1];

  pre[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    cin >> data[i];
    pre[i] = data[i] + pre[i - 1];
  }

  while (q--)
  {
    cin >> a >> b;
    cout << pre[b] - pre[a - 1] << endl;
  }

  return 0;
}