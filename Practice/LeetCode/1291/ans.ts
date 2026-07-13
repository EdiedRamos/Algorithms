function sequentialDigits(low: number, high: number): number[] {
  const sol: number[] = [];

  const digits = (n: number) => Math.floor(Math.log10(n)) + 1;
  const start = digits(low),
  end = digits(high);

  const generate = (n: number) => {
    const ans: number[] = [];
    for (let i = 1; i <= 10 - n; i++) {
      let aux = i;
      let x = i;
      while (digits(x) < n) {
        x *= 10;
        x += ++aux;
      }
      ans.push(x);
    }
    return ans;
  };

  for (let i = start; i <= end; i++) {
    const solutions = generate(i);
    for (const x of solutions) {
      if (x >= low && x <= high) {
        sol.push(x);
      }
    }
  }

  return sol;
}
