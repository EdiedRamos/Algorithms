// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

int Sum(int n) {
  int s = 0;
  while (n) {
    s += n % 10;
    n /= 10;
  }
  return s;
}

int Depth(int n) {
  if (n < 10) {
    return n > 8 ? 1 : -1999999;
  }
  return Depth(Sum(n)) + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int depth, z;
  while (cin >> s && s != "0") {
    z = 0;
    for (char c : s) {
      z += c - '0';
    }
    depth = Depth(z);
    cout << s;
    if (depth < 0) {
      cout << " is not a multiple of 9.\n";
    } else {
      cout << " is a multiple of 9 and has 9-degree " << depth << ".\n";
    }
  }
  return 0;
}
