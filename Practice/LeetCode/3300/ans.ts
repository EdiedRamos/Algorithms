// * 3300. Minimum Element After Replacement With Digit Sum

function minElement(nums: number[]): number {
  return Math.min(
    ...nums.map((value) =>
      String(value)
        .split("")
        .reduce((prev, cur) => prev + Number(cur), 0)
    )
  );
}
