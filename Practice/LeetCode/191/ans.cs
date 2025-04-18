public class Solution {
    public int HammingWeight(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
          if ((n >> i & 1) == 1) {
            count++;
          }
        }
        return count;
    }
}
