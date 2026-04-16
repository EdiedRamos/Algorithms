// 3488. Closest Equal Element Queries

function binarySearch(array: number[], target: number): number {
  let left = 0, right = array.length - 1
  while (left <= right) {
    const middle = (left + right) >> 1
    if (array[middle] === target) return middle
    if (array[middle] > target) right = middle - 1
    else left = middle + 1
  }
  return -1
}

function solveQueries(nums: number[], queries: number[]): number[] {
  const n = nums.length
  const indicesTrack: Record<number, number[]> = {}
  const ans: number[] = []
  for (let i = 0; i < n; i++) {
    if (indicesTrack[nums[i]] === undefined) indicesTrack[nums[i]] = []
    indicesTrack[nums[i]].push(i)
  }
  for (const query of queries) {
    const value = nums[query]
    const indices = indicesTrack[value]
    const idxSize = indices.length
    if (indices.length === 1) {
      ans.push(-1)
      continue
    }
    const startIdx = binarySearch(indices, query)
    let leftDistance = 0, rightDistance = 0
    if (startIdx === 0) {
      leftDistance = indices[startIdx] + (n - indices[idxSize - 1])
    } else {
      leftDistance = indices[startIdx] - indices[startIdx - 1]
    }
    if (startIdx === idxSize -1) {
      rightDistance = (n - indices[idxSize - 1]) + indices[0]
    } else {
      rightDistance = indices[startIdx + 1] - indices[startIdx]
    }
    // console.log({ leftDistance, rightDistance })
    ans.push(Math.min(leftDistance, rightDistance))
  }
  // console.log({ indicesTrack })
  return ans
};