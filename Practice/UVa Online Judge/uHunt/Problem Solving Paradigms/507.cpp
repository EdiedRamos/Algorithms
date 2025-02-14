// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
  return a.second - a.first == b.second - b.first ? a.first < b.first : a.second - a.first > b.second - b.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, stops, value, kadane[20005], x, _max, act_sum;
  kadane[0] = 0;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    vector<pii> rta;
    cin >> stops;
    x = 1;
    _max = -1;
    for (int i = 1; i < stops; i++) {
      cin >> value;
      act_sum = kadane[i - 1] + value;
      if (act_sum < 0) {
        x = i + 1;
        act_sum = 0;
      }
      kadane[i] = act_sum;
      if (kadane[i] > _max) {
        _max = kadane[i];
        rta.clear();
      }
      if (kadane[i] == _max) {
        rta.push_back({x, i + 1});
      }
    }
    sort(rta.begin(), rta.end(), cmp);
    if (_max < 1) {
      cout << "Route " << it << " has no nice parts\n";
    } else {
      cout << "The nicest part of route " << it << " is between stops "<< rta[0].first << " and "<< rta[0].second << "\n";
    }
  }
  return 0;
}