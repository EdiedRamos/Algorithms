// * 985. Sum of Even Numbers After Queries

function sumEvenAfterQueries(nums: number[], queries: number[][]): number[] {
  const ans: number[] = []
  let sum = 0
  for (const value of nums) if (!(value & 1)) sum += value
  for (const [val, index] of queries) {
    if (!(nums[index] & 1)) sum -= nums[index]
    nums[index] += val
    if (!(nums[index] & 1)) sum += nums[index]
    ans.push(sum)
  }
  return ans
}
