// 2807. Insert Greatest Common Divisors in Linked List

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

function gcd(a: number, b: number): number {
  return !b ? a : gcd(b, a % b);
}

function insertGreatestCommonDivisors(head: ListNode | null): ListNode | null {
  let headAux = head;
  while (headAux) {
    if (headAux.next) {
      headAux.next = {
        val: gcd(headAux.val, headAux.next.val),
        next: headAux.next
      }
      headAux = headAux.next;
    }
    headAux = headAux.next;
  }
  return head;
};
