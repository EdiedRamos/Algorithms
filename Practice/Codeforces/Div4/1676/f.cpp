// * F. Longest Strike

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, k, x;
  cin >> t;
  while (t--)
  {
    cin >> n >> k;
    map<int, int> cnt;
    vector<int> filter;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      cnt[x]++;
    }
    for (auto i : cnt)
    {
      if (i.second >= k)
      {
        filter.push_back(i.first);
      }
    }
    if (filter.empty())
    {
      cout << "-1" << endl;
    }
    else
    {
      int idx = 0, Msteps = 0, steps = 0;
      for (int i = 1; i < filter.size(); i++)
      {
        if (filter[i] - 1 == filter[i - 1])
        {
          steps++;
        }
        else
        {
          steps = 0;
        }
        if (steps > Msteps)
        {
          Msteps = steps;
          idx = i;
        }
      }
      cout << filter[idx - Msteps] << " " << filter[idx] << endl;
    }
  }
  return 0;
}