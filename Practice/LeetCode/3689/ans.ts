// * 3689. Maximum Total Subarray Value I

function maxTotalValue(nums: number[], k: number): number {
  const maxValue = Math.max(...nums)
  const minValue = Math.min(...nums)
  return (maxValue - minValue) * k
}
