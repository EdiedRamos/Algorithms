// * H1. Maximum Crossings (Easy Version)

// coder: Yeshayah

// TLE - Just checking if the aproach works, cuz bf O(n^2) works ;)

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef vector<int> vi;
typedef long long ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  ll ans = 0;
  vi::iterator it;
  cin >> t;
  while (t--)
  {
    cin >> n;
    ans = 0;
    vi d(n), aux;
    for (int &i : d)
      cin >> i;
    aux = d;
    sort(aux.begin(), aux.end());
    for (int i : d)
    {
      it = lower_bound(aux.begin(), aux.end(), i);
      aux.erase(it);
      it = upper_bound(aux.begin(), aux.end(), i);
      ans += (it - aux.begin()) * 1LL;
    }
    cout << ans << endl;
  }
  return 0;
}