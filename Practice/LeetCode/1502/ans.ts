// * 1502. Can Make Arithmetic Progression From Sequence

function canMakeArithmeticProgression(arr: number[]): boolean {
  if (arr.length < 3) return true
  arr.sort((a, b) => a - b)
  const constDiff = arr[1] - arr[0]
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] - arr[i - 1] !== constDiff) return false
  }
  return true
}
