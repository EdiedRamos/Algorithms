//Coder: Yeshayah
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

struct Submit {
    int problem, time;
    bool status;
};

bool _cmp(Submit A, Submit B) {
    return A.time < B.time;
}

struct Team {
    bool _sol[7] = {0};
    int _sub[7] = {0};
    int _id, pro_res = 0, total_time = 0;
    vector<Submit> submit_list;
    void Save_Submit(int problem, int time, bool status) {
        submit_list.push_back({problem, time, status});
    }
    void _Submit() {
        sort(submit_list.begin(), submit_list.end(), _cmp);
        for (auto i : submit_list) {
            if (!_sol[i.problem]) {
                if (i.status) {
                    pro_res++;
                    total_time += _sub[i.problem] + i.time;
                    _sol[i.problem] = 1;
                } else _sub[i.problem] += 20;
            }
        }
    }
};

int getTime(string s) {
    return (s[0] - '0') * 60 + atoi(s.substr(2, 2).c_str());
}

bool cmp(Team A, Team B) {
    return A.pro_res == B.pro_res ? A.total_time == B.total_time ?A._id < B._id  : A.total_time < B.total_time : A.pro_res > B.pro_res;
}

bool Diff(Team A, Team B) {
    return A.pro_res != B.pro_res || A.total_time != B.total_time;
}

int Digits(int n) {
    return log10(n) + 1;
}

vs split(string s) {
    vs r;
    string _c = "";
    for (char c : s) {
        if (c == ' ') {
            if (!_c.empty()) {
                r.emplace_back(_c);
                _c = "";
            }
        } else _c += c;
    }
    if (!_c.empty()) r.emplace_back(_c);
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc, MTeam;
    bool _j = 0;
    string s;
    getline(cin, s);
    tc = atoi(s.c_str());
    getline(cin, s);
    while (tc--) {
        map<int, Team> teams;
        int team;
        string problem, time, status;
        MTeam = 0;
        while (getline(cin, s) && !s.empty()) {
            vs prt = split(s);
            team = atoi(prt[0].c_str());
            MTeam = max(team, MTeam);
            problem = prt[1];
            time = prt[2];
            status = prt[3];
            teams[team].Save_Submit(problem[0] - 'A', getTime(time), status == "N" ? 0 : 1);
        }
        for (int i = 1; i <= MTeam; i++) {
            if (teams.find(i) == teams.end()) {
                teams[i];
            }
            teams[i]._Submit();
        }
        vector<Team> new_teams;
        for (auto &i : teams) {
            i.second._id = i.first;
            new_teams.emplace_back(i.second);
        }
        sort(new_teams.begin(), new_teams.end(), cmp);
        if (_j) cout << "\n";
        _j = 1;
        cout << "RANK TEAM PRO/SOLVED TIME\n";
        int _rank = 1;
        for (int i = 0; i < new_teams.size(); i++) {
            if (i && Diff(new_teams[i], new_teams[i-1])) _rank = i + 1;
            for (int sp = 0; sp < 4 - Digits(_rank); sp++) cout << " ";
            cout << _rank << " ";
            for (int sp = 0; sp < 4 - Digits(new_teams[i]._id); sp++) cout << " ";
            cout << new_teams[i]._id;
            if (!new_teams[i].pro_res) {
                cout << "\n";
                continue;
            }
            cout << " ";
            for (int sp = 0; sp < 4 - Digits(new_teams[i].pro_res); sp++) cout << " ";
            cout << new_teams[i].pro_res << "       ";
            for (int sp = 0; sp < 4 - Digits(new_teams[i].total_time); sp++) cout << " ";
            cout << new_teams[i].total_time << "\n";
        }
    }
    return 0;
}
