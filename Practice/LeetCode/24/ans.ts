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

function swapPairs(head: ListNode | null): ListNode | null {
  let aux = head;
  while (aux !== null) {
    if (aux.next) {
      const tmp = aux.val;
      aux.val = aux.next.val;
      aux.next.val = tmp;
      aux = aux.next;
    }
    aux = aux.next;
  }  
  return head;
};
