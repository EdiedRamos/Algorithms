// * 46. Permutations

function permute(nums: number[]): number[][] {
  const answer: number[][] = []
  const options = new Set([...nums])
  const dfs = (combination: number[]) => {
    if (options.size === 0) {
      answer.push(combination)
      return
    }

    for (let i = 0; i < nums.length; i++) {
      const currentValue = nums[i]
      if (options.has(currentValue)) {
        options.delete(currentValue)
        dfs([...combination, currentValue])
        options.add(currentValue)
      }
    }
  }
  dfs([])
  return answer
}
