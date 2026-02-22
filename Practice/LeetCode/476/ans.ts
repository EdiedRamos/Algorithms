// 476. Number Complement

function findComplement(num: number): number {
  const bits = Math.floor(Math.log2(num)) + 1;
  // for (let i = 0; i < bits; i++) {
  //   num ^= 1 << i;
  // }
  return num ^ ((1 << bits) - 1);
}
