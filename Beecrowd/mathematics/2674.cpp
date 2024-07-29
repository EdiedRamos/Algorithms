/*
  [Mathematics]

  Super Primes: Engage!

  The Association of Indivisible Primes ​​elected a category of prime numbers called Super Primes. A number is considered super prime if in addition to being prime, all its digits are prime, too. The Association asked you to make a program to characterize the numbers.

  # Input
  The input contains several test cases, each test case being an integer N (0 < N < 105) on a single line. The entry ends in the last test case.

  # Output
  For each test case, the entry number classification is expected in a single line, which can be: "Super", if the number is a Super Prime; "Primo" if the number by a prime number only; Or "Nada" if the number has divisors beyond 1 and itself.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1e5 + 5

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<bool> isPrime(MAX_N, true);

  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 2; i < MAX_N; i++)
  {
    if (isPrime[i])
    {
      for (int j = i + i; j < MAX_N; j += i)
      {
        isPrime[j] = false;
      }
    }
  }

  int value;

  while (cin >> value)
  {
    if (!isPrime[value])
    {
      cout << "Nada\n";
    }
    else
    {
      bool isSuperPrime = true;
      while (value && isSuperPrime)
      {
        if (!isPrime[value % 10])
        {
          isSuperPrime = false;
        }
        value /= 10;
      }
      cout << (isSuperPrime ? "Super" : "Primo") << "\n";
    }
  }

  return 0;
}