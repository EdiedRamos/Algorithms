// * 3684. Maximize Sum of At Most K Distinct Elements

function maxKDistinct(nums: number[], k: number): number[] {
  const diff = new Set(nums)
  const sorted = [...diff].sort((a, b) => a - b)
  const answer: number[] = []
  while (k > 0 && sorted.length > 0) {
    answer.push(sorted.pop()!)
    k--
  }
  return answer
}
