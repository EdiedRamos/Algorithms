//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string word;
    int m;
    char act;
    bool ok;
    map<char, vector<char>> lad;
    map<char, int> pesos;
    vector<string> index;
    while (cin >> word) {
        if (word == "#") {
            for (string s : index) {
                for (char c : s) {
                    pesos[c] = 0;
                }
            }
            for (int i = 0; i < index.size() - 1; i++) {
                m = min(index[i].size(), index[i+1].size());
                for (int j = 0; j < m; j++) {
                    if (index[i][j] != index[i+1][j]) {
                        ok = 1;
                        for (char c : lad[index[i][j]]) {
                            if (c == index[i+1][j]) {
                                ok = 0;
                                break;
                            }
                        }
                        if (ok) {
                            lad[index[i][j]].push_back(index[i+1][j]);
                            pesos[index[i+1][j]]++;
                        }
                        break;
                    }
                }
            }
            while (1) {
                char act = '~';
                for (auto &i : pesos) {
                    if (i.second == 0) {
                        act = i.first;
                        i.second--;
                        break;
                    }
                }
                if (act == '~') break;
                cout << act;
                for (auto i : lad[act]) {
                    pesos[i]--;
                }
            }
            cout << "\n";
            lad.clear();
            pesos.clear();
            index.clear();
        } else {
            index.push_back(word);
        }
    }
    return 0;
}
