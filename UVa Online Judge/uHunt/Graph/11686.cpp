//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 1000005
    
vector<int> lad[MN];
int peso[MN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v, a, b, act;
    vector<int> topo;
    while (cin >> n >> v && n || v) {
        priority_queue<int, vector<int>, greater<int>> pq;
        topo.clear();
        for (int i = 1; i <= n; i++) {
            peso[i] = 0;
            lad[i].clear();
        }
        while (v--) {
            cin >> a >> b;
            lad[a].push_back(b);
            peso[b]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!peso[i]) {
                pq.push(i);
            }
        }
        while (!pq.empty()) {
            act = pq.top();
            pq.pop();
            if (peso[act] > 0) {
                break;
            }
            topo.push_back(act);
            for (int i : lad[act]) {
                peso[i]--;
                if (!peso[i]) {
                    pq.push(i);
                }
            }
        }
        if (topo.size() == n) {
            for (int i : topo) {
                cout << i << "\n";
            }
        } else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
