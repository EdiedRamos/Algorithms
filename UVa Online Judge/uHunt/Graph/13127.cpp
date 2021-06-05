/*
  █   █ █▀▀▀ █▀▀▀█ █  █ █▀▀█ █   █ █▀▀█ █  █
  █▄▄▄█ █▀▀▀ ▀▀▀▄▄ █▀▀█ █▄▄█ █▄▄▄█ █▄▄█ █▀▀█
    █   █▄▄▄ █▄▄▄█ █  █ █  █   █   █  █ █  █
*/
#include <bits/stdc++.h>
using namespace std;

#define MN 1005

typedef pair<int, int> pii;

const int INF = 1e9;

int n, m, b, p, x, y, w, _max;
priority_queue<pii, vector<pii>, greater<pii>> pq;
pii cu;
vector<int> res, police;
vector<pii> lad[MN];
int dt[MN];
map<int, int> pd;

void dijkstra() { // calls dijkstra with all the police's nodes
  for (int i : police) {
    dt[i] = 0;
    pq.push({0, i});
  }
  while (!pq.empty()) {
    cu = pq.top();
    pq.pop();
    if (cu.first > dt[cu.second]) continue;
    for (pii i : lad[cu.second]) {
      if (dt[cu.second] + i.second < dt[i.first]) {
        dt[i.first] = dt[cu.second] + i.second;
        pq.push({dt[i.first], i.first});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n >> m >> b >> p) {
    pd.clear();
    res.clear();
    police.clear();
    _max = -INF;
    for (int i = 0; i < n; i++) {
      lad[i].clear();
      dt[i] = INF;
    }
    while (m--) {
      cin >> x >> y >> w;
      lad[x].push_back({y, w});
      lad[y].push_back({x, w});
    }
    while (b--) {
      cin >> x;
      pd[x] = INF;
    }
    while (p--) {
      cin >> x;
      police.push_back(x);
    }
    dijkstra();
    for (auto &i : pd) {
      _max = max(_max, dt[i.first]);
      i.second = dt[i.first];
    }
    for (auto i : pd) {
      if (i.second == _max) {
        res.push_back(i.first);
      }
    }
    cout << res.size() << " ";
    if (_max == INF) cout << "*\n";
    else cout << _max << "\n";
    for (int i = 0; i < res.size(); i++) {
      if (i) cout << " ";
      cout << res[i];
    }
    cout << "\n";
  }
  return 0;
}
