// * 3678. Smallest Absent Positive Greater Than Average

function smallestAbsent(nums: number[]): number {
  let average = nums.reduce((a, b) => a + b, 0) / nums.length
  for (let i = 1; ; i++) {
    if (i > average && !nums.includes(i)) {
      return i
    }
  }
  return average
}
