// coder: EdiedRamos

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, onesA, onesB, diffC, swapA, swapB;
    string a, b;
    cin >> tc;
    for (int it = 1; it <= tc; it++) {
        cin >> a >> b;
        onesA = onesB = swapA = swapB = diffC = 0;
        for (int i = 0; i < a.size(); i++) {
            onesA += a[i] == '1';
            onesB += b[i] == '1';
            diffC += a[i] == '?';
            swapA += a[i] == '1' && b[i] == '0';
            swapB += a[i] == '0' && b[i] == '1';
        }
        cout << "Case " << it << ": " << (onesA > onesB ? -1 : diffC + max(swapA, swapB)) << endl;
    }
    return 0;
}
