// * 1281. Subtract the Product and Sum of Digits of an Integer

function digitsSum(n: number): number {
  return n < 1 ? n : digitsSum(Math.floor(n / 10)) + (n % 10);
}

function digitsProduct(n: number): number {
  return n < 1 ? 1 : digitsProduct(Math.floor(n / 10)) * (n % 10);
}

function subtractProductAndSum(n: number): number {
  return digitsProduct(n) - digitsSum(n);
}
