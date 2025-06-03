// * 1047. Remove All Adjacent Duplicates In String

// ? Remove directives comments for local editors
// #include <bits/stdc++.h>
// using namespace std;

class Solution
{
public:
  string removeDuplicates(string s)
  {
    deque<char> remaining;
    for (int i = 0; i < s.size(); i++)
    {
      if (!remaining.empty() && remaining.back() == s[i])
      {
        remaining.pop_back();
      }
      else
      {
        remaining.emplace_back(s[i]);
      }
    }
    string answer = "";
    while (!remaining.empty())
    {
      answer.push_back(remaining.front());
      remaining.pop_front();
    }
    return answer;
  }
};