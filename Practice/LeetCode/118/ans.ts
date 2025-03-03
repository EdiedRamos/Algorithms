// 118. Pascal's Triangle

function generate(numRows: number): number[][] {
  let pascalTriangle: number[][] = [[1]];
  for (let i = 2; i <= numRows; i++) {
    pascalTriangle.push(Array.from({ length: i }).map(() => 1));
    for (let j = 1; j < i - 1; j++) {
      pascalTriangle[i - 1][j] =
        pascalTriangle[i - 2][j] + pascalTriangle[i - 2][j - 1];
    }
  }
  return pascalTriangle;
}
