// 1926. Nearest Exit from Entrance in Maze

function nearestExit(maze: string[][], entrance: number[]): number {
  const n = maze.length,
    m = maze[0].length;

  const [startX, startY] = entrance;

  const queue: [number, number, number][] = [[startX, startY, 0]];
  let queueHead = 0;

  maze[startX][startY] = "+";

  const directions = [
    [1, 0],
    [-1, 0],
    [0, 1],
    [0, -1],
  ];

  while (queueHead < queue.length) {
    const [curX, curY, curDist] = queue[queueHead++];
    for (const [mx, my] of directions) {
      const nextX = curX + mx;
      const nextY = curY + my;
      if (
        nextX >= 0 &&
        nextX < n &&
        nextY >= 0 &&
        nextY < m &&
        maze[nextX][nextY] === "."
      ) {
        if (nextX === 0 || nextX === n - 1 || nextY === 0 || nextY === m - 1) {
          return curDist + 1;
        }
        queue.push([nextX, nextY, curDist + 1]);
        maze[nextX][nextY] = "+";
      }
    }
  }

  return -1;
}
