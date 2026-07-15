// 3658. GCD of Odd and Even Sums

function gcdOfOddEvenSums(n: number): number {
  let sumEven = n * (n + 1);
  let sumOdd = n * n;
  const gcd = (a: number, b: number): number => (!b ? a : gcd(b, a % b));
  return gcd(sumEven, sumOdd);
}
