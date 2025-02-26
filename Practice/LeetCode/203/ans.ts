// 203. Remove Linked List Elements

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

function removeElements(head: ListNode | null, val: number): ListNode | null {
  while (head && head.val === val) head = head.next;
  if (!head) return head;
  let ans = {
    val: head.val,
    next: null
  }
  const ansRef = ans;
  head = head.next;
  while (head !== null) {
    while (head && head.val === val) head = head.next;
    if (head) {
      ans.next = {
        val: head.val,
        next: null
      }
      ans = ans.next;
      head = head.next;
    }
  }
  return ansRef;
};
