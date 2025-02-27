// 1351. Count Negative Numbers in a Sorted Matrix

function countNegatives(grid: number[][]): number {
  let negativeValues = 0;
  for (const row of grid) {
    for (const value of row) {
      if (value < 0) {
        negativeValues++;
      }
    }
  }
  return negativeValues;
};
