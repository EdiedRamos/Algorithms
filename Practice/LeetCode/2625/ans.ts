// * 2625. Flatten Deeply Nested Array

type MultiDimensionalArray = (number | MultiDimensionalArray)[]

function solve(
  data: number | MultiDimensionalArray,
  level: number,
  maxLevel: number
) {
  if (typeof data === 'number' || maxLevel === 0 || level > maxLevel) {
    return [data]
  }
  const flatted: MultiDimensionalArray = []
  for (const d of data) {
    flatted.push(...solve(d, level + 1, maxLevel))
  }
  return flatted
}

var flat = function (
  arr: MultiDimensionalArray,
  n: number
): MultiDimensionalArray {
  if (n === 0) return arr
  return solve(arr, 0, n)
}
