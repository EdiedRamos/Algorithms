// 1886. Determine Whether Matrix Can Be Obtained By Rotation

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

function areEquals(matA: number[][], matB: number[][]): boolean {
  const n = matA.length,
    m = matA[0].length;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (matA[i][j] !== matB[i][j]) {
        return false;
      }
    }
  }
  return true;
}

function findRotation(mat: number[][], target: number[][]): boolean {
  for (let i = 0; i < 4; i++) {
    rotate(mat);
    if (areEquals(mat, target)) {
      return true;
    }
  }
  return false;
}
