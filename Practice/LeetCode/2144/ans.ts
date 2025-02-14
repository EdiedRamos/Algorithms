function minimumCost(cost: number[]): number {
  let total = 0;
  cost.sort((a, b) => b - a);
  for (let i = 1; i <= cost.length; i++) {
    if (i % 3 !== 0) {
      total += cost[i - 1];
    }
  }
  return total;
};
