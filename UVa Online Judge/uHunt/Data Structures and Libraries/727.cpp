// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

// + - * /

map<char, int> peso = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

string solve(string s) {
  string post = "";
  stack<char> signos;
  for (char c : s) {
    if (c == '(') {
      signos.push(c);
    } else if (c == ')') {
      while (signos.top() != '(') {
        post += signos.top();
        signos.pop();
      }
      signos.pop();
    } else if (c >= '0' && c <= '9') {
      post += c;
    } else {
      while (!signos.empty() && peso[signos.top()] >= peso[c]) {
        post += signos.top();
        signos.pop();
      }
      signos.push(c);
    }
  }
  while (!signos.empty()) {
    post += signos.top();
    signos.pop();
  }
  return post;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  string s, infijo = "";
  cin.ignore();
  getline(cin, s);
  while (getline(cin, s)) {
    if (s == "") {
      cout << solve(infijo) << "\n\n";
      infijo = "";
    } else {
      infijo += s;
    }
  }
  cout << solve(infijo) << "\n";
  return 0;
}
