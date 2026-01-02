// 961. N-Repeated Element in Size 2N Array

function repeatedNTimes(nums: number[]): number {
  const used: Record<number, boolean> = {};
  for (const n of nums) {
    if (used[n]) return n;
    used[n] = true;
  }
  return 0;
}
