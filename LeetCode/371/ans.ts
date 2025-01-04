function getSum(a: number, b: number): number {
  while (b) {
    const carry = a & b;
    a ^= b;
    b = carry << 1;
  }
  return a;
};
