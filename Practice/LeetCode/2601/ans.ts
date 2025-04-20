// * 2601. Prime Subtraction Operation

function isPrime(n: number): boolean {
  if (n === 2) return true;
  if ((n & 1) === 0 || n < 2) return false;
  for (let i = 3; i * i <= n; i += 2) {
    if (n % i === 0) {
      return false;
    }
  }
  return true;
}

function getPrimes(n: number): number[] {
  const primes: number[] = [];
  for (let i = 2; i <= n; i++) {
    if (isPrime(i)) {
      primes.push(i);
    }
  }
  return primes;
}

function findPrimePosition(primes: number[], target: number): number {
  let index = -1;
  for (let i = 0; i < primes.length; i++) {
    if (primes[i] < target) {
      index = i;
    }
  }
  return index;
}

function primeSubOperation(nums: number[]): boolean {
  const primes = getPrimes(1000);
  for (let i = 0; i < nums.length; i++) {
    const primeIndex = findPrimePosition(primes, nums[i]);
    for (let j = primeIndex; j >= 0; j--) {
      if (i === 0 || nums[i] - primes[j] > nums[i - 1]) {
        nums[i] -= primes[j];
        break;
      }
    }
    if (i > 0 && nums[i] <= nums[i - 1]) {
      return false;
    }
  }
  return true;
}
