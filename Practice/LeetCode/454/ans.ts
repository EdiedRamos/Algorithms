// 454. 4Sum II

function fourSumCount(
  nums1: number[],
  nums2: number[],
  nums3: number[],
  nums4: number[],
): number {
  let tuples = 0;
  const n = nums1.length;
  const sumFre: Record<number, number> = {};
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      const sum = nums1[i] + nums2[j];
      sumFre[sum] = (sumFre[sum] ?? 0) + 1;
    }
  }
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      const sum = nums3[i] + nums4[j];
      tuples += sumFre[-sum] ?? 0;
    }
  }
  return tuples;
}
