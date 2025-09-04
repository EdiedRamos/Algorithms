// * 202. Happy Number

function getSquareDigitSum(n: number): number {
  let sum = 0
  while (n) {
    sum += Math.pow(n % 10, 2)
    n = Math.floor(n / 10)
  }
  return sum
}

function isHappy(n: number): boolean {
  do {
    n = getSquareDigitSum(n)
  } while (n > 9 || n === 7)
  return n === 1
}
