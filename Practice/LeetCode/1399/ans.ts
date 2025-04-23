function digitsSum(n: number): number {
  // return n < 10 ? n : n % 10 + digitsSum(Math.floor(n / 10));
  let sum: number = 0;
  while (n > 0) {
    sum += n % 10;
    n = Math.floor(n / 10);
  }
  return sum;
}

function countLargestGroup(n: number): number {
  const sizeCount: number[] = Array.from({ length : 37 }).map(() => 0);
  let largestSize: number = 0;
  let answer: number = 0;
  for (let i = 1; i <= n; i++) {
    const sum = digitsSum(i);
    sizeCount[sum]++;
    largestSize = Math.max(largestSize, sizeCount[sum]);
  }
  for (let i = 1; i < 37; i++) {
    if (sizeCount[i] === largestSize) {
      answer++;
    }
  }
  return answer;
};