// * 219. Contains Duplicate II

function containsNearbyDuplicate(nums: number[], k: number): boolean {
  if (k === 0) return false
  const lastPosition: Record<number, number> = {}
  let minimunDistance = Infinity
  for (let i = 0; i < nums.length; i++) {
    const last = lastPosition[nums[i]]
    if (last !== undefined) {
      const distance = i - last
      minimunDistance = Math.min(minimunDistance, distance)
    }
    lastPosition[nums[i]] = i
  }
  return minimunDistance <= k
}
