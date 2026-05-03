// 3917. Count Indices With Opposite Parity

function countOppositeParity(nums: number[]): number[] {
  const n = nums.length;
  const ans: number[] = Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    const currentParity = nums[i] & 1;
    for (let j = i + 1; j < n; j++) {
      if (currentParity !== (nums[j] & 1)) {
        ans[i]++;
      }
    }
  }
  return ans;
}
