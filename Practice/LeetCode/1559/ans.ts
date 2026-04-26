// 1559. Detect Cycles in 2D Grid

function containsCycle(grid: string[][]): boolean {
  const n = grid.length,
    m = grid[0].length;
  const visited: boolean[][] = Array.from({ length: n }, () =>
    Array(m).fill(false),
  );
  let existCycle = false;
  const dfs = (
    x: number,
    y: number,
    lastNode: { x: number; y: number },
    currentVal: string,
  ): void => {
    if (existCycle) return;
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] !== currentVal) return;
    if (visited[x][y]) {
      existCycle = true;
      return;
    }
    visited[x][y] = true;
    if (x + 1 !== lastNode.x) dfs(x + 1, y, { x, y }, currentVal);
    if (y - 1 !== lastNode.y) dfs(x, y - 1, { x, y }, currentVal);
    if (x - 1 !== lastNode.x) dfs(x - 1, y, { x, y }, currentVal);
    if (y + 1 !== lastNode.y) dfs(x, y + 1, { x, y }, currentVal);
  };
  for (let i = 0; i < n && !existCycle; i++) {
    for (let j = 0; j < m && !existCycle; j++) {
      if (!visited[i][j]) {
        dfs(i, j, { x: -1, y: -1 }, grid[i][j]);
      }
    }
  }
  return existCycle;
}
