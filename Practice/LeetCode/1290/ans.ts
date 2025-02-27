// 1290. Convert Binary Number in a Linked List to Integer

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

function getDecimalValue(head: ListNode | null): number {
  const values: number[] = [];
  let result: number = 0;
  while (head) {
    values.unshift(head.val);
    head = head.next;
  }
  for (let i = 0; i < values.length; i++) {
    if (values[i]) {
      result += 1 << i;
    }
  }
  return result;
};
