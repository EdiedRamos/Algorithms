#include <bits/stdc++.h>
using namespace std;

string getGoodGreaterWord(string word) {
  string temporalWord = "", greaterWord = "";
  word += " "; // make sure to get all the good letters
  for (char character : word) {
    character = tolower(character);
    if (character >= 'a' && character <= 'z' || character == '-') temporalWord += character;
    else {
      if (temporalWord.size() > greaterWord.size()) {
        greaterWord = temporalWord;
      }
      temporalWord = "";
    }
  }
  return greaterWord;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string word, greaterWord = "";

  while (cin >> word && word != "E-N-D") {
    string goodWord = getGoodGreaterWord(word);
    if (goodWord.size() > greaterWord.size()) {
      greaterWord = goodWord;
    }
  }

  cout << greaterWord << "\n";

  return 0;
}
