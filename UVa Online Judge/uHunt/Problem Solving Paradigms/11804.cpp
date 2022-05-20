// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct player {
  string name;
  int attacking, defending;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int ii = 1; ii <= tc; ii++) {
    vector<player> players(10);
    bool vis[10];
    int ans[5];
    int _max = 0, _min = 0, attacking, defending;
    for (auto &i : players) {
      cin >> i.name >> i.attacking >> i.defending;
    }
    for (int i = 0; i < 6; i++) {
      for (int j = i + 1; j < 7; j++) {
        for (int k = j + 1; k < 8; k++) {
          for (int l = k + 1; l < 9; l++) {
            for (int m = l + 1; m < 10; m++) {
              memset(vis, 0, sizeof vis);
              vis[i] = vis[j] = vis[k] = vis[l] = vis[m] = 1;
              attacking = defending = 0;
              for (int a = 0; a < 10; a++) {
                if (vis[a]) {
                  attacking += players[a].attacking;
                  defending += players[a].defending;
                }
              }
              if (attacking > _max) {
                ans[0] = i, ans[1] = j, ans[2] = k, ans[3] = l, ans[4] = m;
                _max = attacking;
                _min = defending;
              } else if (attacking == _max) {
                if (defending < _min) {
                  ans[0] = i, ans[1] = j, ans[2] = k, ans[3] = l, ans[4] = m;
                  _min = defending;
                } else if (defending == _min) {
                  set<string> ss, ss2;
                  for (int b = 0; b < 5; b++) {
                    ss.insert(players[ans[b]].name);
                  }
                  for (int b = 0; b < 10; b++) {
                    if (vis[b]) {
                      ss2.insert(players[b].name);
                    }
                  }
                  if (ss2 < ss) {
                    int idx = 0;
                    for (int b = 0; b < 10; b++) {
                      if (vis[b]) {
                        ans[idx++] = b;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    set<string> a, b;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 5; i++) {
      a.insert(players[ans[i]].name);
      vis[ans[i]] = 1;
    }
    for (int i = 0; i < 10; i++) {
      if (!vis[i]) {
        b.insert(players[i].name);
      }
    }
    cout << "Case " << ii << ":" << endl;
    bool sp = 0;
    cout << "(";
    for (string s : a) {
      if (sp) cout << ", ";
      cout << s;
      sp = 1;
    }
    cout << ")\n(";
    sp = 0;
    for (string s : b) {
      if (sp) cout << ", ";
      cout << s;
      sp = 1;
    }
    cout << ")" << endl;
  }
  return 0;
}
