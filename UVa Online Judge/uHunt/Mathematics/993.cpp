// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  bool can;
  vector<int> digits;
  cin >> t;
  while (t--) {
    digits.clear();
    cin >> n;
    can = 1;
    while (n > 9 && can) {
      can = 0;
      for (int i = 9; i > 1; i--) {
        if (n % i == 0) {
          can = 1;
          digits.emplace_back(i);
          n /= i;
          break;
        }
      }
    }
    digits.emplace_back(n);
    if (can) {
      sort(digits.begin(), digits.end());
      for (int i : digits) {
        cout << i;
      }
      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}