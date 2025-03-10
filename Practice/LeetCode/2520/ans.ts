// * 2520. Count the Digits That Divide a Number

function solve(num: number, copy: number): number {
  return num < 1
    ? 0
    : solve(Math.floor(num / 10), copy) + (copy % (num % 10) === 0 ? 1 : 0);
}

function countDigits(num: number): number {
  return solve(num, num);
}
