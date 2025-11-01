// * 3217. Delete Nodes From Linked List Present in Array

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

function modifiedList(nums: number[], head: ListNode | null): ListNode | null {
  let headM: ListNode | null = null
  let aux: ListNode | null = null

  const hasNumber = Array(nums.length + 5).fill(false)
  for (const v of nums) hasNumber[v] = true

  while (head !== null) {
    if (!hasNumber[head.val]) {
      if (headM === null) {
        headM = {
          val: head.val,
          next: null,
        }
        aux = headM
      } else {
        headM.next = {
          val: head.val,
          next: null,
        }
        headM = headM.next
      }
    }
    head = head.next
  }
  return aux
}
