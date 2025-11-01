// * 23. Merge k Sorted Lists

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

function concatenateListToArray(
  list: ListNode | null,
  previousArray: number[]
): number[] {
  let head = list
  while (head !== null) {
    previousArray.push(head.val)
    head = head.next
  }
  return previousArray
}

function arrayToList(array: number[]): ListNode | null {
  let head: ListNode | null = null
  let aux: ListNode | null = null
  for (const v of array) {
    if (head === null) {
      head = {
        val: v,
        next: null,
      }
      aux = head
    } else {
      aux.next = {
        val: v,
        next: null,
      }
      aux = aux.next
    }
  }
  return head
}

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
  let mergedArray: number[] = []
  for (const list of lists) {
    concatenateListToArray(list, mergedArray)
  }
  mergedArray.sort((a, b) => a - b)
  return arrayToList(mergedArray)
}
