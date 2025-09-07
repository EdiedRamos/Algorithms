// * D. X-Sum

// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MN 205

int n, m, chessboard[MN][MN];

bool valid(int x, int y)
{
  return x >= 0 && y >= 0 && x < n && y < m;
}

int ul(int x, int y)
{
  if (!valid(x, y))
    return 0;
  return chessboard[x][y] + ul(x - 1, y - 1);
}

int ur(int x, int y)
{
  if (!valid(x, y))
    return 0;
  return chessboard[x][y] + ur(x - 1, y + 1);
}

int dl(int x, int y)
{
  if (!valid(x, y))
    return 0;
  return chessboard[x][y] + dl(x + 1, y - 1);
}

int dr(int x, int y)
{
  if (!valid(x, y))
    return 0;
  return chessboard[x][y] + dr(x + 1, y + 1);
}

int getScore(int x, int y)
{
  return ul(x - 1, y - 1) + ur(x - 1, y + 1) + dl(x + 1, y - 1) + dr(x + 1, y + 1) + chessboard[x][y];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, _max;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> chessboard[i][j];
      }
    }
    _max = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        _max = max(_max, getScore(i, j));
      }
    }
    cout << _max << endl;
  }
  return 0;
}