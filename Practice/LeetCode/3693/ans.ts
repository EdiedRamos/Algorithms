// * 3693. Climbing Stairs II

function climbStairs(n: number, costs: number[]): number {
  const memo: Record<number, number> = {}
  costs.unshift(0)

  const backtracking = (currentIndex: number, cost: number): number => {
    if (currentIndex > n) return 9999999999
    if (currentIndex === n) return cost
    if (memo[currentIndex] !== undefined) return memo[currentIndex] + cost
    memo[currentIndex] = Math.min(
      backtracking(
        currentIndex + 1,
        (costs[currentIndex + 1] ?? 9999999999) + 1
      ),
      backtracking(
        currentIndex + 2,
        (costs[currentIndex + 2] ?? 9999999999) + 4
      ),
      backtracking(
        currentIndex + 3,
        (costs[currentIndex + 3] ?? 9999999999) + 9
      )
    )
    return memo[currentIndex] + cost
  }

  return backtracking(0, 0)
}
