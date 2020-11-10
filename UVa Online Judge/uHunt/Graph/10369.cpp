//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 505

struct Punto {
    double x, y;
};

struct Arco {
    int a, b;
    double dist;
};

int ds[MN], _rank[MN], s, p;
vector<Punto> puntos;
vector<Arco> arcos, mst;

bool cmp(Arco a, Arco b) {
    return a.dist < b.dist;
}

double Dt(Punto a, Punto b) {
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

int Find(int v) {
    return ds[v] = ds[v] == v ? v : Find(ds[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (_rank[a] < _rank[b]) swap(a, b);
    ds[b] = a;
    _rank[a] += _rank[b];
}

void Generar() {
    for (int i = 0; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            arcos.push_back({i, j, Dt(puntos[i], puntos[j])});
        }
    }
    sort(arcos.begin(), arcos.end(), cmp);
    int c = 0, i = 0, A, B;
    while (c < p - 1 && i < arcos.size()) {
        A = Find(arcos[i].a);
        B = Find(arcos[i].b);
        if (A != B) {
            mst.push_back(arcos[i]);
            Union(A, B);
            c++;
        }
        i++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    Punto act;
    cin >> tc;
    while (tc--) {
        cin >> s >> p;
        arcos.clear();
        puntos.clear();
        mst.clear();
        for (int i = 0; i < p; i++) {
            ds[i] = i;
            _rank[i] = 1;
            cin >> act.x >> act.y;
            puntos.push_back(act);
        }
        Generar();
        s--;
        cout << fixed << setprecision(2) << mst[mst.size() - s - 1].dist << "\n";
    }
    return 0;
}
