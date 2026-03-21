// 3643. Flip Square Submatrix Vertically

function reverseSubmatrix(
  grid: number[][],
  x: number,
  y: number,
  k: number,
): number[][] {
  let decrement = 1;
  for (let i = x; decrement <= k >> 1; i++) {
    const last = x + k - decrement++;
    for (let j = y; j < y + k; j++) {
      [grid[i][j], grid[last][j]] = [grid[last][j], grid[i][j]];
    }
  }
  return grid;
}
