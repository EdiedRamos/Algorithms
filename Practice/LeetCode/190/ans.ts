// * 190. Reverse Bits

function reverseBits(n: number): number {
  let result = 0
  for (let i = 0; i < 32; i++) {
    if (n & (1 << i)) {
      result |= 1 << (31 - i)
    }
  }
  return result
}
