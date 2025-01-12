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

function removeNodes(head: ListNode | null): ListNode | null {
  const asArray: number[] = [];
  while (head !== null) {
    asArray.push(head.val);
    head = head.next;
  }
  const greater: number[] = Array(asArray.length).fill(-1);
  const stack: number[] = [];
  for (let i = asArray.length - 1; i >= 0; i--) {
    while (stack.length > 0 && asArray[stack[stack.length - 1]] <= asArray[i]) {
      stack.pop();
    }
    if (stack.length > 0) {
      greater[i] = asArray[stack[stack.length - 1]];
    }
    stack.push(i);
  }
  let resultHead: ListNode | null = null;
  let resultRoot: ListNode | null = null;
  for (let i = 0; i < greater.length; i++) {
    if (greater[i] === -1) {
      if (resultHead === null) {
        resultHead = {
          val: asArray[i],
          next: null
        }
        resultRoot = resultHead;
      } else {
        resultHead.next = {
          val: asArray[i],
          next: null
        }
        resultHead = resultHead.next;
      }
    }
  }
  return resultRoot;
};
