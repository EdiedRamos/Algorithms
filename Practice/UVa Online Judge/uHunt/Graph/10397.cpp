//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

#define MN 760

struct Edge {
    int a, b;
    double dt;
};

struct Point {
    double x, y;
};

int ds[MN], _r[MN], n, r;
vector<Point> pointl;
vector<Edge> edgel;

bool cmp(Edge a, Edge b) {
    return a.dt < b.dt;
}

double Distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int Find(int x) {
    return ds[x] = ds[x] == x ? x : Find(ds[x]);
}

void Union(int x, int y) {
    if (_r[x] < _r[y]) swap(x, y);
    ds[y] = x;
    _r[x] += _r[y];
}

double Kruskall() {
    double t = 0.0;
    sort(edgel.begin(), edgel.end(), cmp);
    int i = 0, c = 0, A, B;
    while (i < edgel.size() && c < n - 1) {
        A = Find(edgel[i].a);
        B = Find(edgel[i].b);
        if (A != B) {
            t += edgel[i].dt;
            Union(A, B);
            c++;
        }
        i++;
    }
    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Point act;
    int a, b, ch;
    while (cin >> n) {
        pointl.clear();
        edgel.clear();
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
        cout << fixed << setprecision(2) << Kruskall() << "\n";
    }
    return 0;
}
