function largestInteger(nums: number[], k: number): number {
  const frecuency = Array(55).fill(0);
  for (const v of nums) frecuency[v]++;

  if (k === 1) {
    let ans = -1;
    for (let i = 0; i < 51; i++) {
      if (frecuency[i] === 1) {
        ans = Math.max(ans, i);
      }
    }
    return ans;
  }

  if (k === nums.length) {
    return Math.max(...nums);
  }

  const first = nums[0];
  const last = nums[nums.length - 1];
  return frecuency[first] === 1 && frecuency[last] === 1
    ? Math.max(first, last)
    : frecuency[first] === 1
      ? first
      : frecuency[last] === 1
        ? last
        : -1;
}
