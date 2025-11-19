// * 728. Self Dividing Numbers

function isSelfDividing(n: number): boolean {
  const asStr = String(n)
  for (const s of asStr) {
    if (s === '0' || n % +s !== 0) return false
  }
  return true
}

function selfDividingNumbers(left: number, right: number): number[] {
  let ans: number[] = []
  for (let i = left; i <= right; i++) {
    if (isSelfDividing(i)) {
      ans.push(i)
    }
  }
  return ans
}
