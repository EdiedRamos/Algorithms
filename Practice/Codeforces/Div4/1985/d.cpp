// * D. Manhattan Circle

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct Row
{
  int start, length;
};

Row getPartLength(string row)
{
  int length = 0;
  int start = -1;
  for (int i = 0; i < row.size(); i++)
  {
    if (row[i] == '#')
    {
      length++;
      if (!~start)
      {
        start = i;
      }
    }
  }
  Row result;
  result.start = start;
  result.length = length;
  return result;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n, tc, clength, rowCenter;
  Row current, best;
  string row, centerRow;
  cin >> tc;
  while (tc--)
  {
    cin >> m >> n;
    best.length = 0;
    for (int i = 0; i < m; i++)
    {
      cin >> row;
      current = getPartLength(row);
      if (current.length > best.length)
      {
        rowCenter = i;
        centerRow = row;
        best = current;
      }
    }
    cout << rowCenter + 1 << " " << best.start + (best.length >> 1) + 1 << endl;
  }
  return 0;
}