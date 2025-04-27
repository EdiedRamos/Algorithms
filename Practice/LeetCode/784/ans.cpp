// * 784. Letter Case Permutation

class Solution
{
public:
  void generate(int index, string currentString, vector<string> &ans)
  {
    if (index == currentString.size())
    {
      ans.push_back(currentString);
      return;
    }
    generate(index + 1, currentString, ans);
    char character = currentString[index];
    if (character >= 'a' && character <= 'z' || character >= 'A' && character <= 'Z')
    {
      generate(index + 1, applyChange(currentString, index), ans);
    }
  }

  string applyChange(string value, int index)
  {
    char character = value[index];
    if (character >= 'a' && character <= 'z')
    {
      value[index] &= ~32;
    }
    else if (character >= 'A' && character <= 'Z')
    {
      value[index] |= 32;
    }
    return value;
  }
  vector<string> letterCasePermutation(string s)
  {
    vector<string> answer;
    generate(0, s, answer);
    return answer;
  }
};