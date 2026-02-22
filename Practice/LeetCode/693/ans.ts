// 693. Binary Number with Alternating Bits

function hasAlternatingBits(n: number): boolean {
  const bits = Math.floor(Math.log2(n)) + 1;
  for (let i = 0; i < bits - 1; i++) {
    if (!!(n & (1 << i)) === !!(n & (1 << (i + 1)))) {
      return false;
    }
  }
  return true;
}
