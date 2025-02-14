function minimumSum(num: number): number {
  const numbers = num.toString().split("").map(Number).sort((a, b) => a - b);
  return (numbers[0] * 10 + numbers[2]) + (numbers[1] * 10 + numbers[3]);
};
