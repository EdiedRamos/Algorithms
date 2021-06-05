/*
  █   █ █▀▀▀ █▀▀▀█ █  █ █▀▀█ █   █ █▀▀█ █  █
  █▄▄▄█ █▀▀▀ ▀▀▀▄▄ █▀▀█ █▄▄█ █▄▄▄█ █▄▄█ █▀▀█
    █   █▄▄▄ █▄▄▄█ █  █ █  █   █   █  █ █  █
*/
#include <bits/stdc++.h>
using namespace std;

#define MN 105
#define INF 1e9

int x, y, w, p, r, bh, of, yh, m, me_mad[MN][MN], boss_mad[MN][MN], danger[MN];

void fw(int mad[MN][MN]) {
  for (int k = 1; k <= p; k++) {
    if (danger[k]) continue;
    for (int i = 1; i <= p; i++) {
      if (danger[i]) continue;
      for (int j = 1; j <= p; j++) {
        if (danger[j]) continue;
        if (mad[i][j] > mad[i][k] + mad[k][j]) {
          mad[i][j] = mad[i][k] + mad[k][j];
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> p >> r >> bh >> of >> yh >> m) {
    for (int i = 1; i <= p; i++) {
      for (int j = 1; j <= p; j++) {
        me_mad[i][j] = INF;
        boss_mad[i][j] = INF;
      }
      me_mad[i][i] = boss_mad[i][i] = 0;
    }
    memset(danger, 0, sizeof danger);
    while (r--) {
      cin >> x >> y >> w;
      me_mad[x][y] = boss_mad[x][y] = w;
      me_mad[y][x] = boss_mad[y][x] = w;
    }
    fw(boss_mad);
    for (int i = 1; i <= p; i++) {
      if (boss_mad[bh][of] == boss_mad[bh][i] + boss_mad[i][of]) danger[i] = 1;
    }
    if (danger[yh] || danger[m]) {
      cout << "MISSION IMPOSSIBLE.\n";
      continue;
    }
    fw(me_mad);
    if (me_mad[yh][m] == INF) {
      cout << "MISSION IMPOSSIBLE.\n";
    } else {
      cout << me_mad[yh][m] << "\n";
    }
  }
  return 0;
}
