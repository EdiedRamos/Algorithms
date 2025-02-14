// coder: EdiedRamos

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string, string> morse = {
{".-","A"},
{".---","J"},
{"...","S"},
{".----","1"},
{".-.-.-","."},
{"---...",":"},
{"-...","B"},
{"-.-","K"},
{"-","T"},
{"..---","2"},
{"--..--",","},
{"-.-.-.",";"},
{"-.-.","C"},
{".-..","L"},
{"..-","U"},
{"...--","3"},
{"..--..","?"},
{"-...-","="},
{"-..","D"},
{"--","M"},
{"...-","V"},
{"....-","4"},
{".----.","\'"},
{".-.-.","+"},
{".","E"},
{"-.","N"},
{".--","W"},
{".....","5"},
{"-.-.--","!"},
{"-....-","-"},
{"..-.","F"},
{"---","O"},
{"-..-","X"},
{"-....","6"},
{"-..-.","/"},
{"..--.-","_"},
{"--.","G"},
{".--.","P"},
{"-.--","Y"},
{"--...","7"},
{"-.--.","("},
{".-..-.","\""},
{"....","H"},
{"--.-","Q"},
{"--..","Z"},
{"---..","8"},
{"-.--.-",")"},
{".--.-.","@"},
{"..","I"},
{".-.","R"},
{"-----","0"},
{"----.","9"},
{".-...","&"}
};
    int cases;
    bool canSpace;
    string code, aux, message;
    cin >> cases;
    cin.ignore();
    for (int i = 1; i <= cases; i++) {
        canSpace = 0;
        if (i > 1) cout << endl;
        getline(cin, code);
        if (code[code.size() - 1] != ' ') code += " ";
        aux = "";
        message = "";
        for (char c : code) {
            if (c == ' ') {
                if (aux != "") {
                    message += morse[aux];
                    aux = "";
                    canSpace = 1;
                }
                else {
                    if (canSpace) {
                        message += " ";
                        canSpace = 0;
                    }
                }

            } else {
                aux += c;
            }
        }
        cout << "Message #" << i << endl << message << endl;
    }
    return 0;
}
