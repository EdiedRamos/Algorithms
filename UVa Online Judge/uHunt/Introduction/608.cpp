// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> d) {
  set<int> si;
  for (int i : d) {
    si.insert(i);
  }
  return si.size() == 1 && d[0] != 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, max_n;
  string left, right, result;
  cin >> n;
  while (n--) {
    map<char, vector<int>> info;
    max_n = 0;
    for (int i = 0; i < 3; i++) {
      cin >> left >> right >> result;
      x = result[0] == 'e' ? 0 : result[0] == 'd' ? -1 : 1;
      for (char c : right) {
        info[c].push_back(x);
        max_n = max(max_n, (int)info[c].size());
      }
      x = result[0] == 'e' ? 0 : result[0] == 'd' ? 1 : -1;
      for (char c : left) {
        info[c].push_back(x);
        max_n = max(max_n, (int)info[c].size());
      }
    }
    
    for (int k = max_n; k > 0; k--) {
      for (auto i : info) {
        if (i.second.size() == k && check(i.second)) {
          cout << i.first << " is the counterfeit coin and it is " << (i.second[0] == -1 ? "heavy" : "light") << ".\n";
          goto ex;
        }
      }
    }
    ex:;
  }
  return 0;
}