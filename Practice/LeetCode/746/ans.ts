function minCostClimbingStairs(cost: number[]): number {
  const dp: number[] = Array.from({ length: cost.length + 2 }).map(() => 0);
  const n = cost.length;
  for (let i = n - 1; i >= 0; i--) {
    dp[i] = cost[i] + Math.min(dp[i + 1], dp[i + 2]);
  }
  return Math.min(dp[0], dp[1]);
};
