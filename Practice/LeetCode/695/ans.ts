// 695. Max Area of Island

function maxAreaOfIsland(grid: number[][]): number {
  let ans = 0;
  const n = grid.length,
    m = grid[0].length;

  const dfs = (i: number, j: number): number => {
    if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j]) return 0;
    grid[i][j] = 0;
    return 1 + dfs(i, j - 1) + dfs(i, j + 1) + dfs(i + 1, j) + dfs(i - 1, j);
  };

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (grid[i][j]) {
        ans = Math.max(ans, dfs(i, j));
      }
    }
  }
  return ans;
}
