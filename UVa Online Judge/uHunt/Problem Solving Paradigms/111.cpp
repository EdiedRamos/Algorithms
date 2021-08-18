// coder: Yeshayah

// leer nuevamente el problema - tengo algo mal con el ranking vs orden

#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

vs split(string s) {
  vs r;
  string z = "";
  for (char c : s) {
    if (c == ' ') {
      if (!z.empty()) {
        r.push_back(z);
        z = "";
      }
    } else {
      z += c;
    }
  }
  if (!z.empty()) {
    r.push_back(z);
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, rta;
  string str;
  vs part;
  vector<int> dp(n, 1);
  vector<int> array;
  map<int, int> order;
  while (getline(cin, str)) {
    part = split(str);
    if (part.size() < 2) {
      n = atoi(str.c_str());
      getline(cin, str);
      part = split(str);
      order.clear();
      dp.resize(n);
      array.resize(n + 1);
      for (int i = 0; i < n; i++) {
        array[stoi(part[i]) - 1] = i;
      }
      for (int i = 0; i < n; i++) {
        order[array[i]] = i;
      }
    } else {
      for (int &i : dp) {
        i = 1;
      }
      int arr[n];
      for (int i = 0; i < n; i++) {
        arr[stoi(part[i]) - 1] = i;
      }
      for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
          if (order[arr[j]] > order[arr[i]]) {
            dp[j] = max(dp[j], dp[i] + 1);
          }
        }
      }
      rta = 1;
      for (int i = 0; i < n; i++) {
        rta = max(rta, dp[i]);
      }
      cout << rta << "\n";
    }
  }
  return 0;
}