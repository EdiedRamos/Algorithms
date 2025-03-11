// * 1342. Number of Steps to Reduce a Number to Zero

function numberOfSteps(num: number): number {
  let steps = 0;
  while (num) {
    if (num & 1) num--;
    else num >>= 1;
    steps++;
  }
  return steps;
};