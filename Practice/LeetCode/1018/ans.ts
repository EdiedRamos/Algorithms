// * 1018. Binary Prefix Divisible By 5

function prefixesDivBy5(nums: number[]): boolean[] {
  const ans: boolean[] = []
  let n = 0
  for (let i = 0; i < nums.length; i++) {
    n = (2 * n + nums[i]) % 5
    ans.push(n === 0)
  }
  return ans
}
