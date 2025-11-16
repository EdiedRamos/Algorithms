// * 2485. Find the Pivot Integer

function pivotInteger(n: number): number {
  let left = 1,
    right = n
  while (left <= right) {
    const pivot = (left + right) >> 1
    const leftSum = (pivot * (pivot + 1)) >> 1
    const rightSum = ((n * (n + 1)) >> 1) - (leftSum - pivot)
    if (leftSum === rightSum) return pivot
    if (leftSum < rightSum) left = pivot + 1
    else right = pivot - 1
  }
  return -1
}
