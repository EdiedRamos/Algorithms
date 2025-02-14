// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, ans, aux;
  while (cin >> n) {
    string tab[n];
    for (int i = 0; i < n; i++) {
      cin >> tab[i];
    }
    ans = 0;
    vector<pii> start, end;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (tab[i][j] == '1') {
          start.push_back({i,j});
        }
        if (tab[i][j] == '3') {
          end.push_back({i, j});
        }
      }
    }
    for (pii i : start) {
      aux = 1e9;
      for (pii j : end) {
        aux = min(aux, abs(i.first - j.first) + abs(i.second - j.second));
      }
      ans = max(ans, aux);
    }
    cout << ans << "\n";
  }
  return 0;
}