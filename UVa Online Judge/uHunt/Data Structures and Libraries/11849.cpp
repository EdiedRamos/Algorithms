// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c, v;
  while (cin >> a >> b && a || b) {
    unordered_set<int> sA;
    c = 0;
    while (a--) {
      cin >> v;
      sA.insert(v);
    }
    while (b--) {
      cin >> v;
      c += sA.find(v) != sA.end();
    }
    cout << c << "\n";
  }
  return 0;
}