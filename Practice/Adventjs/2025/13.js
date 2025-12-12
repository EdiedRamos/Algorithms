/**
 * @param {string[]} factory - The factory layout
 * @returns {'completed'|'broken'|'loop'} Result of the gift journey
 */
function runFactory(factory) {
  const visited = Array.from({ length: factory.length }).map(() => new Array(factory[0].length).map(() => false))
  let status = 'completed'

  const direction = {
    '>': [0, 1],
    '<': [0, -1],
    '^': [-1, 0],
    'v': [1, 0]
  }

  const dfs = (i, j) => {
    const brokenI = i < 0 || i >= factory.length
    const brokenJ = j < 0 || j >= factory[0].length
    if (brokenI || brokenJ) {
      status = 'broken'
      return
    }

    if (visited[i][j]) {
      status = 'loop'
      return
    }

    if (factory[i][j] === '.') {
      status = 'completed'
      return
    }

    visited[i][j] = true
    const [nextI, nextJ] = direction[factory[i][j]]
    dfs(i + nextI, j + nextJ)
  }
  dfs(0, 0)

  return status
}
