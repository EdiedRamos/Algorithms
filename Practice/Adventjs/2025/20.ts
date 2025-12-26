// Vertical warehouse

function dropGifts(warehouse: string[][], drops: number[]): string[][] {
  const rows = warehouse.length;
  const columns = warehouse[0].length;
  const groupDrops: number[] = Array.from({ length: columns }, () => 0);
  for (const drop of drops) {
    groupDrops[drop]++;
  }
  for (let col = 0; col < columns; col++) {
    for (let row = rows - 1; row >= 0; row--) {
      if (warehouse[row][col] === "." && groupDrops[col] > 0) {
        warehouse[row][col] = "#";
        groupDrops[col]--;
      }
    }
  }
  return warehouse;
}

console.log(
  dropGifts(
    [
      [".", ".", "."],
      [".", "#", "."],
      ["#", "#", "."],
    ],
    [0],
  ),
);
/*
[
  ['.', '.', '.'],
  ['#', '#', '.'],
  ['#', '#', '.']
]
*/

console.log(
  dropGifts(
    [
      [".", ".", "."],
      ["#", "#", "."],
      ["#", "#", "#"],
    ],
    [0, 2],
  ),
);

/*
[
  ['#', '.', '.'],
  ['#', '#', '#'],
  ['#', '#', '#']
]
*/

console.log(
  dropGifts(
    [
      [".", ".", "."],
      [".", ".", "."],
      [".", ".", "."],
    ],
    [0, 1, 2],
  ),
);

/*
[
  ['.', '.', '.'],
  ['.', '.', '.'],
  ['#', '#', '#']
]
*/

console.log(
  dropGifts(
    [
      ["#", "#"],
      ["#", "#"],
    ],
    [0, 0],
  ),
);

/*
[
  ['#', '#']
  ['#', '#']
]
*/
