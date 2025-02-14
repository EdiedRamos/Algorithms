#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string operar(char op, string operacion) {
  ll a, b;
  int l, r;
  string aux;
  for (int i = 0; i < operacion.size(); i++) {
    if (operacion[i] == op) {
      l = i - 1;
      while (l >= 0 && isdigit(operacion[l])) {
        l--;
      }
      r = i + 1;
      while (r < operacion.size() && isdigit(operacion[r])) {
        r++;
      }
      l++, r--;
      a = 0, b = 0;
      for (int x = l; x < i; x++) {
        a = a * 10 + (operacion[x] - '0');
      }
      for (int x = i + 1; x <= r; x++) {
        b = b * 10 + (operacion[x] - '0');
      }
      aux = "";
      for (int x = 0; x < l; x++) {
        aux += operacion[x];
      }
      if (op == '*') {
        a *= b;
      } else if (op == '+') {
        a += b;
      }
      aux += to_string(a);
      for (int x = r + 1; x < operacion.size(); x++) {
        aux += operacion[x];
      }
      break;
    }
  }
  return aux;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  string operacion;
  while (t--) {
    cin >> operacion;
    string aux = operacion;
    int sumas = 0, multiplicaciones = 0;
    for (char c : operacion) {
      sumas += c == '+';
      multiplicaciones += c == '*';
    }
    for (int i = 0; i < multiplicaciones; i++) {
      operacion = operar('*', operacion);
    }
    for (int i = 0; i < sumas; i++) {
      operacion = operar('+', operacion);
    }
    while (sumas--) {
      aux = operar('+', aux);
    }
    while (multiplicaciones--) {
      aux = operar('*', aux);
    }
    cout << "The maximum and minimum are " << aux << " and " << operacion << ".\n";
  }
  return 0;
}