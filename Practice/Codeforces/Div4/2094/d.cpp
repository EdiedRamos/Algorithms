#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<string> findGroups(string s)
{
  vector<string> groups;
  char current = s[0];
  string currentGroup = "";
  for (char c : s)
  {
    if (c == current)
    {
      currentGroup += c;
    }
    else
    {
      groups.push_back(currentGroup);
      currentGroup = "";
      currentGroup += c;
      current = c;
    }
  }
  if (currentGroup.size() > 0)
    groups.push_back(currentGroup);
  return groups;
}

bool verifyCombination(int hit, int heard)
{
  return heard >= hit && heard <= 2 * hit;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  string hits, heard;
  cin >> tc;
  while (tc--)
  {
    cin >> hits >> heard;
    vector<string> hitsGroup = findGroups(hits);
    vector<string> heardGroup = findGroups(heard);

    if (hitsGroup.size() == heardGroup.size())
    {
      bool isCorrect = true;
      for (int i = 0; i < hitsGroup.size() && isCorrect; i++)
      {
        if (!verifyCombination(hitsGroup[i].size(), heardGroup[i].size()) || hitsGroup[i][0] != heardGroup[i][0])
        {
          isCorrect = false;
        }
      }
      cout << (isCorrect ? "YES" : "NO") << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}