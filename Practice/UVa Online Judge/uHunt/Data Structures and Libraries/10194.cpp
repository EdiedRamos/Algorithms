//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

struct Team {
    string _name;
    int _points = 0, _gPlayed = 0, _wins = 0, _ties = 0, _losses = 0, _gDiff = 0, _gScor = 0, _gAga = 0;
};

typedef vector<string> vs;

vs split(string s, char del) {
    vs r;
    string _c = "";
    for (char c : s) {
        if (c == del) {
            if (!_c.empty()) {
                r.push_back(_c);
                _c = "";
            }
        } else _c += c;
    }
    if (!_c.empty()) r.push_back(_c);
    return r;
}

string ToUpper(string s) {
    string r = "";
    for (char c : s) r += c & 95;
    return r;
}

bool cmp(Team A, Team B) {
    return A._points == B._points ? A._wins == B._wins ? A._gDiff == B._gDiff ? A._gScor == B._gScor ? A._gPlayed == B._gPlayed ? ToUpper(A._name) < ToUpper(B._name) : A._gPlayed < B._gPlayed : A._gScor > B._gScor : A._gDiff > B._gDiff : A._wins > B._wins : A._points > B._points;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, nt;
    bool _j = 0;
    int tc, t, _posA, _posB, _gA, _gB;
    getline(cin, s);
    tc = atoi(s.c_str());
    while (tc--) {
        getline(cin, nt);
        getline(cin, s);
        t = atoi(s.c_str());
        vector<Team> _info(t);
        map<string, int> dir;
        while (t--) {
            getline(cin, s);
            dir[s] = dir.size();
        }
        for (auto i : dir) _info[i.second]._name = i.first;
        getline(cin, s);
        t = atoi(s.c_str());
        while (t--) {
            getline(cin, s);
            for (char &c : s) if (c == '@') {
                c = '#';
                break;
            }
            vs prt = split(s, '#');
            _gA = atoi(prt[1].c_str());
            _gB = atoi(prt[2].c_str());
            _posA = dir[prt[0]];
            _posB = dir[prt[3]];
            _info[_posA]._gPlayed++;
            _info[_posA]._gScor += _gA;
            _info[_posA]._gAga += _gB;
            _info[_posB]._gPlayed++;
            _info[_posB]._gScor += _gB;
            _info[_posB]._gAga += _gA;
            if (_gA  == _gB) {
                _info[_posA]._ties++, _info[_posB]._ties++, _info[_posA]._points++, _info[_posB]._points++;
            } else if (_gA > _gB) {
                _info[_posA]._points += 3, _info[_posA]._wins++, _info[_posB]._losses++;
            } else {
                _info[_posB]._points += 3, _info[_posB]._wins++, _info[_posA]._losses++;
            }
        }
        for (Team &i : _info) i._gDiff = i._gScor - i._gAga;
        sort(_info.begin(), _info.end(), cmp);
        if (_j) cout << "\n";
        _j = 1;
        if (nt[0] == ' ') {
            int l = 0;
            while (l < nt.size() && nt[l] == ' ') l++;
            nt = nt.substr(l, nt.size() - l);
        }
        cout << nt << "\n";
        for (int i = 0; i < _info.size(); i++) {
            cout << (i+1) << ") " << _info[i]._name << " " << _info[i]._points << "p, " << _info[i]._gPlayed << "g (" << _info[i]._wins << "-" << _info[i]._ties << "-" << _info[i]._losses << "), " << _info[i]._gDiff << "gd (" << _info[i]._gScor << "-" << _info[i]._gAga << ")\n";
        }
    }
    return 0;
}
