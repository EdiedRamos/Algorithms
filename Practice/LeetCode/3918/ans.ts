// 3918. Sum of Primes Between Number and Its Reverse

function isPrime(n: number): boolean {
  if (n < 2) return false;
  if (n === 2) return true;
  if (!(n & 1)) return false;
  for (let i = 3; i * i <= n; i += 2) {
    if (n % i === 0) {
      return false;
    }
  }
  return true;
}

function sumOfPrimesInRange(n: number): number {
  const b = +[...`${n}`].reverse().join("");
  const l = Math.min(n, b),
    r = Math.max(n, b);
  let ans = 0;
  for (let i = l; i <= r; i++) {
    if (isPrime(i)) {
      ans += i;
    }
  }
  return ans;
}
