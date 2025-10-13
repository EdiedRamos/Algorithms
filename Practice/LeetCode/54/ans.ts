// * 54. Spiral Matrix

function spiralOrder(matrix: number[][]): number[] {
  const MAX_VALUE = 999
  const answer: number[] = []
  const xMove = [0, 1, 0, -1]
  const yMove = [1, 0, -1, 0]

  const dfs = (x: number, y: number, direction: number) => {
    if (
      x < 0 ||
      y < 0 ||
      x === matrix.length ||
      y === matrix[0].length ||
      matrix[x][y] === MAX_VALUE
    )
      return
    answer.push(matrix[x][y])
    matrix[x][y] = MAX_VALUE
    const order = [direction]
    for (let i = direction + 1; i < 4; i++) order.push(i)
    for (let i = 0; i < direction; i++) order.push(i)
    for (const d of order) dfs(x + xMove[d], y + yMove[d], d)
  }
  dfs(0, 0, 0)

  return answer
}
