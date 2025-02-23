// 83. Remove Duplicates from Sorted List

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

type Node = ListNode | null;

function deleteDuplicates(head: Node): Node {
  if (!head) return null;

  let headAux: Node = {
    val: head.val,
    next: null
  };
  const headRef = headAux;
  while (head !== null) {
    if (head.val !== headAux.val) {
      headAux.next = {
        val: head.val,
        next: null
      };
      headAux = headAux.next;
    }
    head = head.next;
  }
  return headRef;
};
