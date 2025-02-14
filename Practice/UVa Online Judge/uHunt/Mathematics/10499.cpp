#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long n;
  while (cin >> n && n > 0) {
    cout << (n < 2 ? 0 : n * 25) << "%" << endl;
  }
  return 0;
}
