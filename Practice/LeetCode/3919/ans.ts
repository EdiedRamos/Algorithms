// 3919. Minimum Cost to Move Between Indices

function minCost(nums: number[], queries: number[][]): number[] {
  const n = nums.length;
  const closestLR: number[] = Array(n).fill(0);
  const closestRL: number[] = Array(n).fill(0);
  let moveCost;
  for (let i = 0; i < n - 1; i++) {
    if (i === 0) moveCost = 1;
    else {
      const diffLeft = Math.abs(nums[i - 1] - nums[i]);
      const diffRight = Math.abs(nums[i + 1] - nums[i]);
      moveCost = diffRight < diffLeft ? 1 : diffRight;
    }
    closestLR[i + 1] = closestLR[i] + moveCost;
  }
  for (let i = n - 1; i > 0; i--) {
    if (i === n - 1) moveCost = 1;
    else {
      const diffLeft = Math.abs(nums[i - 1] - nums[i]);
      const diffRight = Math.abs(nums[i + 1] - nums[i]);
      moveCost = diffLeft <= diffRight ? 1 : diffLeft;
    }
    closestRL[i - 1] = closestRL[i] + moveCost;
  }
  // console.log({ closest })
  const ans: number[] = [];
  for (const [l, r] of queries) {
    if (l <= r) ans.push(closestLR[r] - closestLR[l]);
    else ans.push(closestRL[r] - closestRL[l]);
  }
  return ans;
}
