// 160. Intersection of Two Linked Lists

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

function getIntersectionNode(headA: ListNode | null, headB: ListNode | null): ListNode | null {
  let auxA = headA;
  let auxB = headB;

  while (auxA !== auxB) {
    auxA = !auxA ? headB : auxA.next;
    auxB = !auxB ? headA : auxB.next;
  }
  return auxA;
};
