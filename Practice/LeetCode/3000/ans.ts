// * 3000. Maximum Area of Longest Diagonal Rectangle

function areaOfMaxDiagonal(dimensions: number[][]): number {
  const op = dimensions
    .map(([length, width]) => [
      Math.sqrt(length * length + width * width),
      length * width,
    ])
    .sort(([a, a1], [b, a2]) => (a === b ? a2 - a1 : b - a))
  return op[0][1]
}
