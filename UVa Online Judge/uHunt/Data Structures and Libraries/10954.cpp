// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, v, cost, sum;
  while (cin >> n, n) {
    priority_queue<int> pq;
    cost = 0;
    while (n--) {
      cin >> v;
      pq.push(-v);
    }
    while (pq.size() > 1) {
      sum = -pq.top();
      pq.pop();
      sum += -pq.top();
      pq.pop();
      cost += sum;
      pq.push(-sum);
    }
    cout << cost << "\n";
  }
  return 0;
}