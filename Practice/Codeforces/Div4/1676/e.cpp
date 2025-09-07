// * E. Eating Queries

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef long long ll;

int t, n, q, x;

bool cmp(int a, int b)
{
  return a > b;
}

int binary_seach(vector<ll> &arr, int target)
{
  if (target > arr[n - 1])
    return -1;
  int l = 0, r = n - 1, c;
  while (l <= r)
  {
    c = (l + r) >> 1;
    if (arr[c] == target)
      return c + 1;
    if (arr[c] > target)
      r = c - 1;
    else
      l = c + 1;
  }
  return l + 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--)
  {
    cin >> n >> q;
    vector<ll> d(n);
    for (ll &i : d)
      cin >> i;
    sort(d.begin(), d.end(), cmp);
    vector<ll> sum(n);
    sum[0] = d[0];
    for (int i = 1; i < n; i++)
    {
      sum[i] = sum[i - 1] + d[i];
    }
    while (q--)
    {
      cin >> x;
      cout << binary_seach(sum, x) << endl;
    }
  }
  return 0;
}