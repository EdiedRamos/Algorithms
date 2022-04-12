// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool check(char c) {
    string vowels = "aeiou";
    for (char cc : vowels) if (c == cc) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string a, b;
    map<string, string> irregular;
    cin >> n >> m;
    while (n--) {
        cin >> a >> b;
        irregular[a] = b;
    }
    while (m--) {
        cin >> a;
        if (irregular.find(a) != irregular.end()) cout << irregular[a] << endl;
        else if (a.size() > 1 && a[a.size() - 1] == 'y' && check(a[a.size() - 2])) cout << a.substr(0, a.size() - 1) << "ies" << endl;
        else if (a[a.size() - 1] == 'o' || a[a.size() - 1] == 's' || a[a.size() - 1] == 'x') cout << a << "es" << endl;
        else if (a.size() > 1 && ((a[a.size() - 1] == 'h') && (a[a.size() - 2] == 'c' || a[a.size() - 2] == 's'))) cout << a << "es" << endl;
        else cout << a << "s" << endl;
    }
    return 0;
}
