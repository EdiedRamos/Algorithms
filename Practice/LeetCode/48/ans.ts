// 48. Rotate Image

/**
 Do not return anything, modify matrix in-place instead.
 */
function rotate(matrix: number[][]): void {
  const n = matrix.length;
  const copy: number[][] = Array(n)
    .fill(null)
    .map(() => Array(n).fill(0));
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      copy[i][j] = matrix[i][j];
    }
  }
  let x = n - 1,
    y = 0;
  for (let i = 0; i < n; i++) {
    x = n - 1;
    for (let j = 0; j < n; j++) {
      matrix[i][j] = copy[x][y];
      x--;
    }
    y++;
  }
}
