//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool winner;
    int t, p, sl, rd, a, b;
    cin >> t;
    while (t--) {
        winner = 0;
        cin >> p >> sl >> rd;
        vector<int> info(101);
        vector<int> pos(p, 1);
        while (sl--) {
            cin >> a >> b;
            info[a] = b;
        }
        for (int i = 0; i < rd; i++) {
            cin >> a;
            if (!winner) {
                pos[i % p] += a;
                if (info[pos[i % p]]) pos[i % p] = info[pos[i % p]];
                if (pos[i % p] == 100) winner = 1;
            }
        }
        for (int i = 0; i < p; i++) cout << "Position of player " << i + 1 << " is " << pos[i] << ".\n";
    }
    return 0;
}
