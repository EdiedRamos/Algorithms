// 1009. Complement of Base 10 Integer

function bitwiseComplement(n: number): number {
  if (!n) return 1;
  const bits = Math.floor(Math.log2(n)) + 1;
  return n ^ ((1 << bits) - 1);
}
