//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 760

struct Point {
    double x, y;
};

struct Edge {
    int a, b;
    double dt;
};

bool cmp(Edge a, Edge b) {
    return a.dt < b.dt;
}

bool cmp2(Edge a, Edge b) {
    return a.a < b.a;
}

int n, r, ds[MN], _r[MN];
vector<Edge> edgel, mst;
vector<Point> pointl;

int Find(int x) {
    return ds[x] = ds[x] == x ? x : Find(ds[x]);
}

double Distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void Union(int x, int y) {
    if (_r[x] < _r[y]) swap(x, y);
    ds[y] = x;
    _r[x] += _r[y];
}

void Kruskall() {
    sort(edgel.begin(), edgel.end(), cmp);
    int i = 0, c = 0, A, B;
    while (i < edgel.size() && c < n - 1) {
        A = Find(edgel[i].a);
        B = Find(edgel[i].b);
        if (A != B) {
            Union(A, B);
            if (edgel[i].dt != 0.0) mst.push_back(edgel[i]);
            c++;
        }
        i++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, a, b;
    bool jm = 0;
    Point act;
    cin >> tc;
    while (tc--) {
        edgel.clear();
        pointl.clear();
        mst.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            ds[i] = i;
            _r[i] = 1;
            cin >> act.x >> act.y;
            pointl.push_back(act);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edgel.push_back({i, j, Distance(pointl[i], pointl[j])});
            }
        }
        cin >> r;
        while (r--) {
            cin >> a >> b;
            a--, b--;
            edgel.push_back({a, b, 0.0});
        }
        Kruskall();
        if (jm) cout << "\n";
        jm = 1;
        if (mst.empty()) {
            cout << "No new highways need\n";
        } else {
            for (auto i : mst) cout << i.a + 1 << " " << i.b + 1 << "\n";
        }
    }
    return 0;
}
