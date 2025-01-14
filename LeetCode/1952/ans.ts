function isThree(n: number): boolean {
    let counter = 0;
    for (let i = 1; i * i <= n; i++) {
      if (n % i === 0) {
        counter++;
        if (i * i !== n) counter++;
        if (counter > 3) return false;
      }
    }
    return counter === 3;
};
