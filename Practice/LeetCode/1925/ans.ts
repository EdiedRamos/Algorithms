// * 1925. Count Square Sum Triples

function countTriples(n: number): number {
  let triples = 0
  for (let i = 1; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const squareSum = i * i + j * j
      const c = Math.floor(Math.sqrt(squareSum))
      if (c * c === squareSum && c <= n) triples++
    }
  }
  return triples * 2
}
