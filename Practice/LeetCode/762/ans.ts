// 762. Prime Number of Set Bits in Binary Representation

function countPrimeSetBits(left: number, right: number): number {
  const primes = Array(32).fill(false);
  for (const prime of [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]) {
    primes[prime] = true;
  }

  let res = 0;
  for (let i = left; i <= right; i++) {
    let bitsOn = 0;
    const n = Math.floor(Math.log2(i)) + 1;
    for (let x = 0; x < n; x++) {
      if (i & (1 << x)) {
        bitsOn++;
      }
    }
    if (primes[bitsOn]) res++;
  }
  return res;
}
