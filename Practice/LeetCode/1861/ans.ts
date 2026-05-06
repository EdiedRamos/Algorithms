// * 1861. Rotating the Box

function rotate90(grid: string[][]): string[][] {
  const n = grid.length;
  const m = grid[0].length;
  const rn = m,
    rm = n;
  const rotated: string[][] = Array.from({ length: rn }).map(() =>
    Array(rm).fill(""),
  );
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      rotated[j][rm - i - 1] = grid[i][j];
    }
  }
  return rotated;
}

function applyGravity(grid: string[][]): void {
  const n = grid.length;
  const m = grid[0].length;
  for (let i = 0; i < m; i++) {
    let stones = 0;
    let empty = 0;
    for (let j = 0; j < n; j++) {
      if (grid[j][i] === "*") {
        for (let k = j - 1; k >= 0 && stones + empty > 0; k--) {
          if (stones > 0) {
            grid[k][i] = "#";
            stones--;
          } else if (empty > 0) {
            grid[k][i] = ".";
            empty--;
          }
        }
        stones = 0;
        empty = 0;
      } else if (grid[j][i] === "#") {
        stones++;
      } else if (grid[j][i] === ".") {
        empty++;
      }
    }
    for (let k = n - 1; k >= 0 && stones + empty > 0; k--) {
      if (stones > 0) {
        grid[k][i] = "#";
        stones--;
      } else if (empty > 0) {
        grid[k][i] = ".";
        empty--;
      }
    }
  }
}

function rotateTheBox(boxGrid: string[][]): string[][] {
  const rotated = rotate90(boxGrid);
  applyGravity(rotated);
  return rotated;
}
