//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 205

struct Stone {
    double x, y;
};

struct Edge {
    int a, b;
    double d;
};

bool cmp(Edge a, Edge b) {
    return a.d < b.d;
}

int ds[MN], _rank[MN], n;
Stone st;
bool vis[MN];
double rta[MN];
vector<pair<int,double>> lad[MN];
vector<Edge> edgel;
vector<Stone> stonel;

int Find(int v) {
    return ds[v] = ds[v] == v ? v : Find(ds[v]);
}

void Union(int a, int b) {
    if (_rank[a] < _rank[b]) swap(a, b);
    ds[b] = a;
    _rank[a] += _rank[b];
}

double Distance(Stone a, Stone b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void Build() {
    for (int i = 0; i < stonel.size(); i++) {
        for (int j = i + 1; j < stonel.size(); j++) {
            edgel.push_back({i, j, Distance(stonel[i], stonel[j])});
        }
    }
}

void Kruskall() {
    sort(edgel.begin(), edgel.end(), cmp);
    int c = 0, i = 0, A, B;
    while (i < edgel.size() && c < n - 1) {
        A = Find(edgel[i].a);
        B = Find(edgel[i].b);
        if (A != B) {
            Union(A, B);
            lad[edgel[i].a].push_back({edgel[i].b, edgel[i].d});
            lad[edgel[i].b].push_back({edgel[i].a, edgel[i].d});
            c++;
        }
        i++;
    }
}

void DFS(int a) {
    vis[a] = 1;
    for (auto i : lad[a]) {
        if (!vis[i.first]) {
            rta[i.first] = max(rta[a], i.second);
            DFS(i.first);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    while (cin >> n && n) {
        stonel.clear();
        edgel.clear();
        rta[0] = -99999999.9;
        for (int i = 0; i < n; i++) {
            lad[i].clear();
            vis[i] = 0;
            ds[i] = i;
            _rank[i] = 1;
            cin >> st.x >> st.y;
            stonel.push_back(st);
        }
        Build();
        Kruskall();
        DFS(0);
        cout << "Scenario #" << tc++ << "\nFrog Distance = ";
        cout << fixed << setprecision(3) << rta[1] << "\n\n";
    }
    return 0;
}
