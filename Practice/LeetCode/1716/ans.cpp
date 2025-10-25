class Solution
{
public:
  int totalMoney(int n)
  {
    int result = 0, start = 1, increment = 1, days = 1;
    for (int i = 0; i < n; i++)
    {
      result += start++;
      days++;
      if (days == 8)
      {
        start = ++increment;
        days = 1;
      }
    }
    return result;
  }
};