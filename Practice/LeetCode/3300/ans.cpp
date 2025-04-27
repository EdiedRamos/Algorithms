// * 3300. Minimum Element After Replacement With Digit Sum

class Solution
{
public:
  int digitSum(int value)
  {
    return value < 10 ? value : value % 10 + digitSum(value / 10);
  }

  int minElement(vector<int> &nums)
  {
    int mini = 1e9;
    for (int value : nums)
    {
      int sum = digitSum(value);
      mini = min(mini, sum);
    }
    return mini;
  }
};