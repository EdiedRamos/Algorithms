// * G. Fall Down

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m, c;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    char grid[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> grid[i][j];
    for (int i = n - 2; i >= 0; i--)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == '*')
        {
          c = i + 1;
          while (c < n && grid[c][j] == '.')
            c++;
          c--;
          swap(grid[c][j], grid[i][j]);
        }
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cout << grid[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}