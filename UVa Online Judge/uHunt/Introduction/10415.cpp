// coder: EdiedRamos

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef vector<pair<int, int>> vpii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    int solution[15];
    bool control[15];
    string song;
    cin >> cases;
    cin.ignore();
    while (cases--) {
        getline(cin, song);
        memset(solution, 0, sizeof solution);
        memset(control, 0, sizeof control);
        for (char c : song) {
            switch (c) {
                case 'c':
                    for (int i = 1; i < 11; i++) {
                        if ((i > 1 && i < 5) || (i > 6)) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'd':
                    for (int i = 1; i < 11; i++) {
                        if ((i > 1 && i < 5) || (i > 6 && i < 10)) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'e':
                    for (int i = 1; i < 11; i++) {
                        if ((i > 1 && i < 5) || (i > 6 && i < 9)) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'f':
                    for (int i = 1; i < 11; i++) {
                        if ((i > 1 && i < 5) || (i == 7)) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'g':
                    for (int i = 1; i < 11; i++) {
                        if (i > 1 && i < 5) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'a':
                    for (int i = 1; i < 11; i++) {
                        if (i > 1 && i < 4) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'b':
                    for (int i = 1; i < 11; i++) {
                        if (i == 2) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'C':
                    for (int i = 1; i < 11; i++) {
                        if (i == 3) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'D':
                    for (int i = 1; i < 11; i++) {
                        if (i < 5 || (i > 6 && i < 10)) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'E':
                    for (int i = 1; i < 11; i++) {
                        if (i < 5 || (i > 6 && i < 9)) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'F':
                    for (int i = 1; i < 11; i++) {
                        if (i < 5 || i == 7) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'G':
                    for (int i = 1; i < 11; i++) {
                        if (i < 5) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'A':
                    for (int i = 1; i < 11; i++) {
                        if (i < 4) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
                case 'B':
                    for (int i = 1; i < 11; i++) {
                        if (i < 3) {
                            if (!control[i]) solution[i]++;
                            control[i] = 1;
                        } else {
                            control[i] = 0;
                        }
                    }
                    break;
            }
        }
        for (int i = 1; i < 11; i++) {
            if (i > 1) cout << " ";
            cout << solution[i];
        }
        cout << endl;
    }
    return 0;
}
