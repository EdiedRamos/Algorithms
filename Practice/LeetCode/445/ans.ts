// * 445. Add Two Numbers II

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

function listToArray(list: ListNode | null): number[] {
  let array: number[] = []
  while (list !== null) {
    array.push(list.val)
    list = list.next
  }
  return array
}

function arrayToList(array: number[]): ListNode | null {
  let head: ListNode | null = null
  let aux: ListNode | null = null
  for (const val of array) {
    if (!head) {
      head = {
        val,
        next: null,
      }
      aux = head
    } else {
      aux.next = {
        val,
        next: null,
      }
      aux = aux.next
    }
  }
  return head
}

function sumOfArrays(array1: number[], array2: number[]): number[] {
  if (array1.length < array2.length)
    array1.unshift(...Array(array2.length - array1.length).fill(0))
  if (array2.length < array1.length)
    array2.unshift(...Array(array1.length - array2.length).fill(0))

  let carry = 0
  for (let i = array1.length - 1; i >= 0; i--) {
    array1[i] += array2[i] + carry
    if (array1[i] > 9) {
      carry = Math.floor(array1[i] / 10)
      array1[i] %= 10
    } else {
      carry = 0
    }
  }
  if (carry) array1.unshift(carry)
  return array1
}

function addTwoNumbers(
  l1: ListNode | null,
  l2: ListNode | null
): ListNode | null {
  return arrayToList(sumOfArrays(listToArray(l1), listToArray(l2)))
}
