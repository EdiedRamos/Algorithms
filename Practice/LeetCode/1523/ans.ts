// * 1523. Count Odd Numbers in an Interval Range

function countOdds(low: number, high: number): number {
  return Math.floor((high - low) / 2 + (high & 1 || low & 1 ? 1 : 0))
}
