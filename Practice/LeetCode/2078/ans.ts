function maxDistance(colors: number[]): number {
  let left = 0;
  let right = 0;
  for (let i = colors.length - 1; i > 0; i--) {
    if (colors[i] !== colors[0]) {
      left = i;
      break;
    }
  }
  for (let i = 0; i < colors.length - 1; i++) {
    if (colors[i] !== colors[colors.length - 1]) {
      right = colors.length - (i + 1);
      break;
    }
  }
  return Math.max(left, right);
};
