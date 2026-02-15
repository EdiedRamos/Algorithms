// 240. Search a 2D Matrix II

function searchMatrix(matrix: number[][], target: number): boolean {
  for (let i = 0; i < matrix.length; i++) {
    if (target < matrix[i][0]) return false;
    let left = 0,
      right = matrix[i].length;
    while (left <= right) {
      const middle = (left + right) >> 1;
      if (matrix[i][middle] === target) return true;
      if (matrix[i][middle] < target) left = middle + 1;
      else right = middle - 1;
    }
  }
  return false;
}
