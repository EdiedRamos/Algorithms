// 1758. Minimum Changes To Make Alternating Binary String

class Solution {
public:
    int minOperations(string s) {
        string optionA = "", optionB = "";
        int changesA = 0, changesB = 0;
        for (int i = 0; i < s.size(); i++) {
          if (i & 1) {
            optionA = "0";
            optionB = "1";
          } else {
            optionA = "1";
            optionB = "0";
          }
          if (s[i] != optionA[0]) changesA++;
          if (s[i] != optionB[0]) changesB++;
        }
        return min(changesA, changesB);
    }
};
