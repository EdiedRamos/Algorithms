// * 1513. Number of Substrings With Only 1s

function numSub(s: string): number {
  const MOD = 1e9 + 7
  let ans = 0,
    co = 0
  s += '0'
  for (const c of s) {
    if (c === '1') co++
    else {
      ans = (ans + (co * (co + 1)) / 2) % MOD
      co = 0
    }
  }
  return ans
}
