// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 10005

bool prime[MN + 1];
vector<int> primes;

void criba() {
  memset(prime, 1, sizeof prime);
  for (int i = 2; i <= MN; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= MN; j += i) {
        prime[j] = 0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  criba();
  int n, sum, ways;
  while (cin >> n && n) {
    ways = prime[n];
    for (int i = 0; i < primes.size() && primes[i] < n; i++) {
      sum = primes[i];
      for (int j = i + 1; j < primes.size() && sum < n; j++) {
        sum += primes[j];
      }
      ways += sum == n;
    }
    cout << ways << "\n";
  }
  return 0;
}