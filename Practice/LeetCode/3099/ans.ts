function sumOfTheDigitsOfHarshadNumber(x: number): number {
  let sum = 0;
  let aux = x;
  while (aux) {
    sum += aux % 10;
    aux = Math.floor(aux / 10);
  }
  return x % sum === 0 ? sum : -1;
};
