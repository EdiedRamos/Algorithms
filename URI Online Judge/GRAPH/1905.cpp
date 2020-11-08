//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

char mapa[5][5];

void Back(int i, int j) {
    if (mapa[i][j] == '~' || i < 0 || j < 0 || i == 5 || j == 5 || mapa[i][j] == '1') return;
    mapa[i][j] = '~';
    Back(i-1, j);
    Back(i+1, j);
    Back(i, j-1);
    Back(i, j+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> mapa[i][j];
            }
        }
        Back(0, 0);
        cout << (mapa[4][4] == '~' ? "COPS" : "ROBBERS") << "\n";
    }
    return 0;
}
