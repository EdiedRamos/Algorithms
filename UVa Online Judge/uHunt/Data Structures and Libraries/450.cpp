//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

struct Info {
    string departament, first_name, last_name, home_address, title, homephone, workphone, campusbox;
};

vs split(string s) {
    vs r;
    string _c;
    for (char c : s) {
        if (c == ',') {
            if (!_c.empty()) {
                r.push_back(_c);
                _c = "";
            }
        } else _c += c;
    }
    if (!_c.empty()) r.push_back(_c);
    return r;
}

bool cmp(Info A, Info B) {
    return A.last_name < B.last_name;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    string s;
    getline(cin, s);
    tc = atoi(s.c_str());
    vector<Info> data;
    Info tmp;
    while (tc--) {
        getline(cin, s);
        tmp.departament = s;
        while (getline(cin, s) && !s.empty()) {
            vs prt = split(s);
            tmp.title = prt[0];
            tmp.first_name = prt[1];
            tmp.last_name = prt[2];
            tmp.home_address = prt[3];
            tmp.homephone = prt[4];
            tmp.workphone = prt[5];
            tmp.campusbox = prt[6];
            data.emplace_back(tmp);
        }
    }
    sort(data.begin(), data.end(), cmp);
    for (auto i : data) {
        cout << "----------------------------------------\n";
        cout << i.title << " " << i.first_name << " " << i.last_name << "\n" << i.home_address << "\n";
        cout << "Department: " << i.departament << "\nHome Phone: " << i.homephone << "\n";
        cout << "Work Phone: " << i.workphone << "\nCampus Box: " << i.campusbox << "\n";
    }
    return 0;
}
