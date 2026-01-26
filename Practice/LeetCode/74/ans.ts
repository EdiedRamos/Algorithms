// 74. Search a 2D Matrix

function searchMatrix(matrix: number[][], target: number): boolean {
  const rows = matrix.length;
  const columns = matrix[0].length;

  let left = 0,
    right = rows * columns - 1;

  while (left <= right) {
    const middle = (left + right) >> 1;
    const row = Math.floor(middle / columns);
    const column = middle % columns;
    if (matrix[row][column] === target) return true;
    if (matrix[row][column] < target) left = middle + 1;
    else right = middle - 1;
  }

  return false;
}
