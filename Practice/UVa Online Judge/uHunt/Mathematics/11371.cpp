// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, a, b;
  while (cin >> n) {
    vector<int> dg;
    while (n) {
      dg.push_back(n % 10);
      n /= 10;
    }
    if (dg.empty()) dg.push_back(0);
    a = 0;
    sort(dg.begin(), dg.end(), cmp);
    for (int i : dg) {
      a = a * 10 + i;
    }
    b = 0;
    sort(dg.begin(), dg.end());
    if (dg[0] == 0) {
      int t = 0;
      while (t < dg.size() && !dg[t]) {t++;}
      swap(dg[0], dg[t]);
    }
    for (int i : dg) {
      b = b * 10 + i;
    }
    cout << a << " - " << b << " = " << a -  b << " = 9 * " << (a - b) / 9 << "\n";
  }
  return 0;
}
