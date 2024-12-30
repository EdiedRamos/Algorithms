function thirdMax(nums: number[]): number {
  const diff = [...new Set(nums)].sort((a, b) => b - a);
  return diff.length > 2 ? diff[2] : diff[0];
};
