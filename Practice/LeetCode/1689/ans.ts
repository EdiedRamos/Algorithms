function minPartitions(n: string): number {
  for (let i = 9; i >= 0; i--) {
    if (n.includes(i.toString())) {
      return i;
    }
  }
  return 0;
};
