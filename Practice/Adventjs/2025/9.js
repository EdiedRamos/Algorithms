// * The reno robot aspirator

/**
 * @param {string} board - Represents the board
 * @param {string} moves - Sequence of moves
 * @returns {'fail' | 'crash' | 'success'}
 */
function moveReno(board, moves) {
  const grid = board.split('\n').slice(1, -1)

  const directions = {
    L: { row: 0, col: -1 },
    R: { row: 0, col: 1 },
    U: { row: -1, col: 0 },
    D: { row: 1, col: 0 },
  }

  let position = { row: 0, col: 0 }
  for (let row = 0; row < grid.length; row++) {
    const col = grid[row].indexOf('@')
    if (col !== -1) {
      position = { row, col }
      break
    }
  }

  for (const move of moves) {
    const dir = directions[move]
    const next = { row: position.row + dir.row, col: position.col + dir.col }

    const outOfBounds =
      next.row < 0 ||
      next.col < 0 ||
      next.row >= grid.length ||
      next.col >= grid[next.row].length

    if (outOfBounds || grid[next.row][next.col] === '#') return 'crash'
    if (grid[next.row][next.col] === '*') return 'success'

    position = next
  }

  return 'fail'
}

const board = `
.....
.*#.*
.@...
.....
`

console.assert(moveReno(board, 'D') === 'fail', '1')
// ➞ 'fail' -> it moves but doesn't pick anything up

console.assert(moveReno(board, 'U') === 'success', '2')
// ➞ 'success' -> it picks something up (*) right above

console.assert(moveReno(board, 'RU') === 'crash', '3')
// ➞ 'crash' -> it crashes into an obstacle (#)

console.assert(moveReno(board, 'RRRUU') === 'success', '4')
// ➞ 'success' -> it picks something up (*)

console.assert(moveReno(board, 'DD') === 'crash', '5')
// ➞ 'crash' -> it crashes into the bottom of the board

console.assert(moveReno(board, 'UUU') === 'success', '6')
// ➞ 'success' -> it picks something up off the floor (*) and then crashes at the top

console.assert(moveReno(board, 'RR') === 'fail', '7')
// ➞ 'fail' -> it moves but doesn't pick anything up
