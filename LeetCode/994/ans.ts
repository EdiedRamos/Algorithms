interface MatrixNode {
  r: number;
  c: number;
}

function orangesRotting(grid: number[][]): number {
  const pending: MatrixNode[] = [], aux: MatrixNode[] = [];
  const m = grid.length;
  const n = grid[0].length;
  let round = -1;

  for (let r = 0; r < m; r++)
    for (let c = 0; c < n; c++)
      if (grid[r][c] === 2)
        pending.push({ r, c });

  while (pending.length > 0) {
    round++;
    while (pending.length > 0) {
      const { r, c } = pending.pop();
      // up
      if (grid[r - 1] && grid[r - 1][c] === 1) {
        grid[r - 1][c] = 2;
        aux.push({ r: r - 1, c });
      }
      // down
      if (grid[r + 1] && grid[r + 1][c] === 1) {
        grid[r + 1][c] = 2;
        aux.push({ r: r + 1, c });
      }
      // left
      if (grid[r][c - 1] === 1) {
        grid[r][c - 1] = 2;
        aux.push({ r, c: c - 1 });
      }
      // right
      if (grid[r][c + 1] === 1) {
        grid[r][c + 1] = 2;
        aux.push({ r, c: c + 1 });
      }
    }
    while (aux.length > 0) pending.push(aux.pop());
  }

  for (let r = 0; r < m; r++)
    for (let c = 0; c < n; c++)
      if (grid[r][c] === 1)
        return -1;

  return Math.max(0, round);
};
