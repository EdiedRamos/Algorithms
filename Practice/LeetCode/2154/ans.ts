// * 2154. Keep Multiplying Found Values by Two

function findFinalValue(nums: number[], original: number): number {
  const valueRecord: Record<number, number> = {}
  for (const n of nums) {
    valueRecord[n] = 1
  }
  while (valueRecord[original]) {
    original *= 2
  }
  return original
}
