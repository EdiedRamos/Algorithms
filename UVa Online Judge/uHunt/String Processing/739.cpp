// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<char, string> soundex_code = {
        {'B', "1"}, {'P', "1"}, {'F', "1"}, {'V', "1"},
        {'C', "2"}, {'S', "2"}, {'K', "2"}, {'G', "2"}, {'J', "2"}, {'Q', "2"}, {'X', "2"}, {'Z', "2"},
        {'D', "3"}, {'T', "3"},
        {'L', "4"},
        {'M', "5"}, {'N', "5"},
        {'R', "6"},
        {'A', ""}, {'E', ""}, {'I', ""}, {'O', ""}, {'U', ""}, {'Y', ""}, {'W', ""}, {'H', ""}
    };
    string name, soundex, code, last;
    for (int i = 0; i < 9; i++) cout << " ";
    cout << "NAME";
    for (int i = 0; i < 21; i++) cout << " ";
    cout << "SOUNDEX CODE" << endl;
    while (cin >> name) {
        soundex = name[0];
        last = soundex_code[soundex[0]];
        for (int i = 1; i < name.size(); i++) {
            code = soundex_code[name[i]];
            if (code == last) continue;
            if (code == "") last = "~";
            else last = code;
            soundex += code;
            if (soundex.size() == 4) break;
        }
        while (soundex.size() < 4) soundex += "0";
        for (int i = 0; i < 9; i++) cout << " ";
        cout << name;
        for (int i = 0; i < 35 - (10 + name.size()); i++) cout << " ";
        cout << soundex << endl;
    }
    for (int i = 0; i < 19; i++) cout << " ";
    cout << "END OF OUTPUT" << endl;
    return 0;
}
