#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  string s;
  bool flag;
  cin >> t;
  cin.ignore();
  while (t--)
  {
    getline(cin, s);
    flag = true;
    for (int i = 0; i < s.size(); i++)
    {
      if (flag)
      {
        cout << s[i];
        flag = false;
      }
      else if (s[i] == ' ')
      {
        flag = true;
      }
    }
    cout << endl;
  }
  return 0;
}