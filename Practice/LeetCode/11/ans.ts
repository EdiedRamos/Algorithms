// * 11. Container With Most Water

function maxArea(height: number[]): number {
  let ans = 0,
    left = 0,
    right = height.length - 1
  while (left < right) {
    const area = Math.min(height[left], height[right]) * (right - left)
    ans = Math.max(ans, area)
    if (height[left] <= height[right]) left++
    else right--
  }
  return ans
}
