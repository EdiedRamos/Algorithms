function combinationSum3(k: number, n: number): number[][] {
    const available = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    const combinations: number[][] = [];
    for (let i = 0; i < (1 << available.length); i++) {
      const option: number[] = [];
      for (let j = 0; j < available.length; j++) {
        if (i & (1 << j)) {
          option.push(available[j]);
        }
      }
      if (option.length === k) {
        const sum = option.reduce((p, c) => p + c, 0);
        if (sum === n) {
          combinations.push(option);
        }
      }
    }
    return combinations;
};
