// * B. Maximum Multiple Sum

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc, x, n, maxSum, sum;
  cin >> tc;
  while (tc--)
  {
    cin >> n;
    maxSum = 0;
    for (int i = 2; i <= n; i++)
    {
      sum = 0;
      int f = 1;
      int j = i;
      while (j * f <= n)
      {
        sum += j * f;
        f++;
      }
      if (sum > maxSum)
      {
        maxSum = sum;
        x = i;
      }
    }
    cout << x << endl;
  }
  return 0;
}