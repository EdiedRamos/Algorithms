// * 3683. Earliest Time to Finish One Task

function earliestTime(tasks: number[][]): number {
  let ans = Infinity
  for (const [a, b] of tasks) {
    const s = a + b
    ans = Math.min(ans, s)
  }
  return ans
}
