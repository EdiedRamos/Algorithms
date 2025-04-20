// * 3115. Maximum Prime Difference

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

function maximumPrimeDifference(nums: number[]): number {
  let start = 0,
    end = 0;
  let flag = false;
  for (let i = 0; i < nums.length; i++) {
    if (isPrime(nums[i])) {
      if (!flag) {
        start = i;
        flag = true;
      }
      end = i;
    }
  }
  return end - start;
}
