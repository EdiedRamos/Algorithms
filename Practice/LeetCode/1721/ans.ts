// 1721. Swapping Nodes in a Linked List

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

function swapNodes(head: Node, k: number): Node {
  let first: Node = null, second: Node = null;
  let headAux = head;
  let index = 1;
  while (headAux !== null) {
    if (index++ === k) {
      first = headAux;
    }
    headAux = headAux.next;
  }
  headAux = head;
  index--;
  while (headAux !== null) {
    if (index-- === k) {
      second = headAux;
    }
    headAux = headAux.next;
  }
  const valAux = first.val;
  first.val = second.val;
  second.val = valAux;
  return head;
};
