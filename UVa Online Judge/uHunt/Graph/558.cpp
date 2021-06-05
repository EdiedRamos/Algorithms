/*
  █   █ █▀▀▀ █▀▀▀█ █  █ █▀▀█ █   █ █▀▀█ █  █
  █▄▄▄█ █▀▀▀ ▀▀▀▄▄ █▀▀█ █▄▄█ █▄▄▄█ █▄▄█ █▀▀█
    █   █▄▄▄ █▄▄▄█ █  █ █  █   █   █  █ █  █
*/
#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc, v, a, x, y, w;
  vector<pii> lad[1005];
  int dt[1005];
  bool cycle;
  cin >> tc;
  while (tc--) {
    cin >> v >> a;
    for (int i = 0; i < v; i++) {
      dt[i] = INF;
      lad[i].clear();
    }
    while (a--) {
      cin >> x >> y >> w;
      lad[x].push_back({y, w});
    }
    for (int i = 0; i < v - 1; i++) {
      cycle = 0;
      for (int j = 0; j < v; j++) {
        for (pii k : lad[j]) {
          if (dt[k.first] > dt[j] + k.second) {
            dt[k.first] = dt[j] + k.second;
            cycle = 1;
          }
        }
      }
      if (!cycle) break;
    }
    cycle = 0;
    for (int j = 0; j < v; j++) {
      for (pii k : lad[j]) {
        if (dt[k.first] > dt[j] + k.second) {
          cycle = 1;
          break;
        }
      }
    }
    cout << (cycle ? "possible\n" : "not possible\n");
  }
  return 0;
}
