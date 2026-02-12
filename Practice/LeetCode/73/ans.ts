// 73. Set Matrix Zeroes

/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix: number[][]): void {
  const zeroRef: { row: number; col: number }[] = [];
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      if (!matrix[i][j]) {
        zeroRef.push({ row: i, col: j });
      }
    }
  }
  for (const { row, col } of zeroRef) {
    for (let i = 0; i < matrix.length; i++) {
      matrix[i][col] = 0;
    }
    for (let i = 0; i < matrix[0].length; i++) {
      matrix[row][i] = 0;
    }
  }
}
