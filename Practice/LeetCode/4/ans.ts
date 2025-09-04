// * 4. Median of Two Sorted Arrays

function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  const n = nums1.length + nums2.length
  let middle = n >> 1
  if (!(n & 1)) middle--
  let index = 0,
    leftIndex = 0,
    rightIndex = 0,
    currentValue = 0
  let sum = 0,
    revision = 0
  while (index < n) {
    if (nums1[leftIndex] <= (nums2[rightIndex] ?? Infinity)) {
      currentValue = nums1[leftIndex++]
    } else {
      currentValue = nums2[rightIndex++]
    }
    if (index === middle) {
      sum += currentValue
      if (revision) return sum / 2
      if (n & 1) return sum
      else middle++
      revision++
    }
    index++
  }
  return 0
}
