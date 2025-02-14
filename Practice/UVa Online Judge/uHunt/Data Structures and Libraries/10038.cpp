// coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, dif;
  while (cin >> n) {
    vector<int> d(n);
    set<int> seti;
    for (int &i : d) {
      cin >> i;
    }
    for(int i = 0; i < n - 1; i++) {
      dif = abs(d[i] - d[i + 1]);
      if (dif < n) {
        seti.insert(dif);
      }
    }
    cout << (seti.size() == n - 1 ? "Jolly\n" : "Not jolly\n");
  }
  return 0;
}