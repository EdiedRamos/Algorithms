class Solution {
public:
    int minPartitions(string n) {
        for (int i = 9; i > 0; i--) {
          for (char c : n) {
            if (c == (i + '0')) {
              return i;
            }
          }
        }
        return 0;
    }
};
