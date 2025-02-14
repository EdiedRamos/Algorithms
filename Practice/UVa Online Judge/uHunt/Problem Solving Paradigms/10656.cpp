// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, v;
  bool sp;
  while (cin >> n && n) {
    sp = 0;
    while (n--) {
      cin >> v;
      if (v) {
        if (sp) {
          cout << " ";
        }
        cout << v;
        sp = 1;
      }
    }
    if (!sp) {
      cout << 0;
    }
    cout << "\n";
  }
  return 0;
}