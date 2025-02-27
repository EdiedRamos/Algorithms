// 2326. Spiral Matrix IV

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function spiralMatrix(m: number, n: number, head: ListNode | null): number[][] {
  const matrix: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));

  const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  let curDir = 0;

  function move(x: number, y: number) {

    if (!head) return;

    matrix[x][y] = head.val;
    head = head.next;

    let nx = x + directions[curDir][0];
    let ny = y + directions[curDir][1];

    if (nx < 0 || ny < 0 || nx >= m || ny >= n || ~matrix[nx][ny]) {
      curDir = (curDir + 1) % 4;
      nx = x + directions[curDir][0];
      ny = y + directions[curDir][1];
    }

    move(nx, ny);
  }
  move(0, 0);

  return matrix;
};
