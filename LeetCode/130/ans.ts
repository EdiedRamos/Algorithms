/**
 Do not return anything, modify board in-place instead.
 */

const OPTIONS_R = [-1, 1, 0, 0];
const OPTIONS_C = [0, 0, -1, 1];

function buildPath(board: string[][], row: number, column: number, path: number[][], visited: boolean[][]): void {
  const isInvalidRow = row < 0 || row >= board.length;
  const isInvalidColumn = column < 0 || column >= board[0].length;
  const isInvalidField = !isInvalidRow && board[row][column] !== "O";
  if (isInvalidRow || isInvalidColumn || isInvalidField || visited[row][column]) return;

  path.push([row, column]);
  visited[row][column] = true;
  for (let i = 0; i < 4; i++)
    buildPath(board, row + OPTIONS_R[i], column + OPTIONS_C[i], path, visited);
}

function pathCanBeSurrounded(board: string[][], path: number[][]): boolean {
  for (const [r, c] of path) {
    for (let i = 0; i < 4; i++) {
      if (!board[r + OPTIONS_R[i]] || !["X", "O"].includes(board[r + OPTIONS_R[i]][c + OPTIONS_C[i]])) return false;
    }
  }
  return true;
}

function surroundPath(board: string[][], path: number[][]) {
  for (const [r, c] of path) {
    board[r][c] = "X";
  }
}

function solve(board: string[][]): void {
  const visited: boolean[][] = [];

  for (let i = 0; i < board.length; i++) {
    visited.push(Array.from({ length: board[i].length }, () => false));
  }

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      if (!visited[i][j] && board[i][j] === "O") {
        const path: number[][] = [];
        buildPath(board, i, j, path, visited);
        if (pathCanBeSurrounded(board, path)) surroundPath(board, path);
        // console.log({ path, can: pathCanBeSurrounded(board, path) });
      }
    }
  }

  // console.log(visited)
};
