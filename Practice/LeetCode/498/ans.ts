// * 498. Diagonal Traverse

function findDiagonalOrder(mat: number[][]): number[] {
  const ans: number[] = []
  const rows = mat.length
  const columns = mat[0].length
  let toReverse = false
  for (let i = 0; i < rows; i++) {
    let temporal: number[] = []
    let _row = i,
      _column = 0
    while (_row >= 0 && _column < columns) {
      temporal.push(mat[_row][_column])
      _row--
      _column++
    }
    if (toReverse) temporal = temporal.reverse()
    ans.push(...temporal)
    toReverse = !toReverse
  }
  for (let i = 1; i < columns; i++) {
    let temporal: number[] = []
    let _row = rows - 1,
      _column = i
    while (_row >= 0 && _column < columns) {
      temporal.push(mat[_row][_column])
      _row--
      _column++
    }
    if (toReverse) temporal = temporal.reverse()
    ans.push(...temporal)
    toReverse = !toReverse
  }
  return ans
}
