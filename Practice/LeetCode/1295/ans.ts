// * 1295. Find Numbers with Even Number of Digits

function findNumbers(nums: number[]): number {
  return nums.filter((value) => (Math.floor(Math.log10(value) + 1) & 1) === 0)
    .length;
}
