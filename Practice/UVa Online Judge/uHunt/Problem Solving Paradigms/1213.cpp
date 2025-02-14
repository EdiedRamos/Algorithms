// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
  if (n == 2) {
    return 1;
  }
  if (n < 2 || !(n & 1)) {
    return 0;
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int n, k, res;
vector<int> primes;
int dp[200][16][1125];

// i -> indice en el que vamos, t -> tamaño del conjunto actual, a -> lo que falta por expresar
int back(int i, int t, int a) {
  if (t == k) { // ya tengo k elementos seleccionados
    return a == 0;
  }
  if (a < 0 || primes[i] > n) { // nos pasamos de la suma o el primo actual es mayor a la suma total
    return 0;
  }
  int &memo = dp[i][t][a];
  if (memo != -1) {
    return memo;
  }
  return memo = back(i + 1, t, a) + back(i + 1, t + 1, a - primes[i]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i <= 1125; i++) {
    if (prime(i)) {
      primes.emplace_back(i);
    }
  }
  while (cin >> n >> k && n || k) {
    memset(dp, -1, sizeof dp);
    cout << back(0, 0, n) << "\n";
  }
  return 0;
}