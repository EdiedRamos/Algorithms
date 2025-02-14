// coder: Yeshayah

#include <bits/stdc++.h>
using namespace std;

#define MN 12

int n, m;
char crossword[MN][MN];
int pos[MN][MN];
bool vis[MN][MN];

void back(int x, int y, bool dir) {
  if (x < 0 || y < 0 || x == n || y == m || vis[x][y] || crossword[x][y] == '*') {
    return;
  }
  printf("%c", crossword[x][y]);
  vis[x][y] = 1;
  if (dir) { // left to right
    back(x, y + 1, dir);
  } else { // up to bottom
    back(x + 1, y, dir);
  }
}

int main() {
  int it = 1, id;
  while (scanf("%d", &n) && n) {
    id = 1;
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> crossword[i][j];
        if ((i - 1  < 0 || j - 1 < 0 || crossword[i - 1][j] == '*' || crossword[i][j - 1] == '*') && crossword[i][j] != '*') {
          pos[i][j] = id++;
        }
      }
    }
    if (it > 1) {
      printf("\n");
    }
    printf("puzzle #%d:\n", it++);
    // across
    memset(vis, 0, sizeof vis);
    printf("Across\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] && crossword[i][j] != '*') {
          printf("%3d.", pos[i][j]);
          back(i, j, 1);
          printf("\n");
        }
      }
    }
    // down
    memset(vis, 0, sizeof vis);
    printf("Down\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] && crossword[i][j] != '*') {
          printf("%3d.", pos[i][j]);
          back(i, j, 0);
          printf("\n");
        }
      }
    }
  }
  return 0;
}