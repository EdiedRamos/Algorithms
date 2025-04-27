// * 2535. Difference Between Element Sum and Digit Sum of an Array

class Solution
{
public:
  int getDigitSum(int value)
  {
    return value < 10 ? value : value % 10 + getDigitSum(value / 10);
  }
  int differenceOfSum(vector<int> &nums)
  {
    int sum = 0;
    int digitSum = 0;
    for (int n : nums)
    {
      sum += n;
      digitSum += getDigitSum(n);
    }
    return abs(sum - digitSum);
  }
};