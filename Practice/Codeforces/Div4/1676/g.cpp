// * G. White-Black Balanced Subtrees

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<vector<int>> lad;

int ans;
string colors;

int dfs(int current)
{
  int balance = 0;
  for (int i : lad[current])
  {
    int aux = dfs(i);
    balance += aux;
    ans += !aux;
  }
  return balance + (colors[current - 1] == 'W' ? 1 : -1);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, x;
  cin >> t;
  while (t--)
  {
    cin >> n;
    lad.clear();
    lad.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
      cin >> x;
      lad[x].push_back(i);
    }
    cin >> colors;
    ans = 0;
    int tmp = dfs(1);
    ans += !tmp;
    cout << ans << endl;
  }
  return 0;
}