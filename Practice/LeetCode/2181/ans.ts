// 2181. Merge Nodes in Between Zeros

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

function mergeNodes(head: Node): Node {
  const resultHead: Node = {
    val: 0,
    next: null
  };
  let resultAux = resultHead;
  let merged = 0;
  while (head) {
    if (head.val === 0 && merged > 0) {
      resultAux.val = merged;
      if (head.next) {
        resultAux.next = {
          val: 0,
          next: null
        }
        resultAux = resultAux.next;
      }
      merged = 0;
    } else {
      merged += head.val;
    }
    head = head.next;
  }
  return resultHead;
};
