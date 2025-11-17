// * 1437. Check If All 1's Are at Least Length K Places Away

function kLengthApart(nums: number[], k: number): boolean {
  let distance = 0
  let startCount = false
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === 1) {
      if (!startCount) {
        startCount = true
        distance = 0
        continue
      }
      if (distance < k) return false
      distance = 0
    } else {
      distance++
    }
  }
  return true
}
