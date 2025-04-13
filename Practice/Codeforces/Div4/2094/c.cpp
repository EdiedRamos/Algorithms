#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc, n;
  cin >> tc;
  while (tc--)
  {
    cin >> n;
    int g[n + 5][n + 5];
    int sol[2 * n + 5];
    memset(sol, sizeof sol, 0);
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        cin >> g[i][j];
      }
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        sol[i + j] = g[i][j];
      }
    }
    int localSum = 0;
    for (int i = 2; i <= 2 * n; i++)
    {
      localSum += sol[i];
    }
    int totalSum = ((2 * n) * (2 * n + 1)) >> 1;
    sol[1] = totalSum - localSum;
    for (int i = 1; i <= 2 * n; i++)
    {
      cout << sol[i] << " ";
    }
    cout << endl;
  }
  return 0;
}