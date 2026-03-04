// 1582. Special Positions in a Binary Matrix

class Solution {
public:
  int numSpecial(vector<vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
    int ans = 0;
    vector<int> countM(m, 0), countN(n, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 1) {
          countM[i]++;
          countN[j]++;
        }
    	}
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 1 && countM[i] == 1 && countN[j] == 1) {
					ans++;
        }
      }
    }
    return ans;
  }
};