//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    vector<pair<int,int>> sol;
    cin >> n;
    for (int _i = 1; _i <= n; _i++) {
        cin >> k;
        sol.clear();
        for (int i = 2; i * i <= k && sol.size() < 2; i++) {
            if (k % i == 0) {
                sol.push_back({i, k / i});
            }
        }
        cout << "Case #" << _i << ": " << k;
        for (int i = 0; i < 2; i++) {
            cout << " = " << sol[i].first << " * " << sol[i].second;
        }
        cout << "\n";
    }
    return 0;
}
