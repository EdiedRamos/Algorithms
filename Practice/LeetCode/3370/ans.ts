// * 3370. Smallest Number With All Set Bits

function smallestNumber(n: number): number {
  let bits = Math.floor(Math.log2(n))
  let value = 1
  let power = 2
  while (bits--) {
    value += power
    power <<= 1
  }
  return value
}
