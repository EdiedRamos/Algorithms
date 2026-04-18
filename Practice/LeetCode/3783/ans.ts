// 3783. Mirror Distance of an Integer

function mirrorDistance(n: number): number {
  let reverse = 0;
  let copy = n;
  while (copy) {
    reverse = reverse * 10 + (copy % 10);
    copy = Math.floor(copy / 10);
  }
  return Math.abs(n - reverse);
}
