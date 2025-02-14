// * B. osu!mania

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef vector<int> vi;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tc, n;
  string r;
  cin >> tc;
  while (tc--)
  {
    vi d;
    cin >> n;
    while (n--)
    {
      cin >> r;
      for (int i = 0; i < 4; i++)
      {
        if (r[i] == '#')
        {
          d.push_back(i + 1);
        }
      }
    }
    bool sp = 0;
    for (int i = d.size() - 1; i >= 0; i--)
    {
      if (sp)
        cout << " ";
      cout << d[i];
      sp = 1;
    }
    cout << endl;
  }
  return 0;
}