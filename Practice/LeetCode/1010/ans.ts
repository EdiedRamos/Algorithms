// * 1010. Pairs of Songs With Total Durations Divisible by 60

function comb(n: number): number {
  return (n * (n - 1)) / 2
}

function numPairsDivisibleBy60(time: number[]): number {
  const mod60: number[] = new Array(60).fill(0)
  let pairs = 0
  for (const t of time) {
    mod60[t % 60]++
  }
  for (let i = 1; i < 30; i++) {
    pairs += mod60[i] * mod60[60 - i]
  }
  pairs += comb(mod60[0]) + comb(mod60[30])
  return pairs
}
