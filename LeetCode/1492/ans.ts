function kthFactor(n: number, k: number): number {
  const divisors = [];
  for (let i = 1; i * i <= n; i++) {
    if (n % i === 0) {
      divisors.push(i);
      if (n / i !== i)
        divisors.push(n / i);
    }
  }
  divisors.sort((a, b) => a - b);
  if (k > divisors.length) return -1;
  return divisors[k - 1];
};
