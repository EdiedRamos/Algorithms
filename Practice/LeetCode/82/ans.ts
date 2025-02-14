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

function deleteDuplicates(head: ListNode | null): ListNode | null {
  let ans = null;
  let build = null;
  let flag = Infinity;
  while (head !== null) {
    if (head.next && head.val === head.next.val) {
      flag = head.val;
    }
    if (flag !== Infinity) {
      while (head !== null && head.val === flag) {
        // console.log("ignorando ", head.val);
        head = head.next;
      }
      flag = Infinity;
    } else {
      if (build === null) {
        build = {
          val: head.val,
          next: null
        };
        ans = build;
      } else {
        build.next = {
          val: head.val,
          next: null
        };
        build = build.next;
      }
      head = head.next;
    }
  }
  return ans;  
};
