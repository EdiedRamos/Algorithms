// * 2197. Replace Non-Coprime Numbers in Array

function gcd(a: number, b: number): number {
  return !b ? a : gcd(b, a % b)
}

function lcm(a: number, b: number): number {
  return (a * b) / gcd(a, b)
}

function lcmpre(a: number, b: number, gcdpre: number) {
  return (a * b) / gcdpre
}

function replaceNonCoprimes(nums: number[]): number[] {
  const calculated: number[] = []
  for (let i = 0; i < nums.length; i++) {
    if (!calculated.length) {
      calculated.push(nums[i])
      continue
    }

    let aux = nums[i]
    while (calculated.length) {
      const lastValue = calculated[calculated.length - 1]
      const currentGcd = gcd(aux, lastValue)

      if (currentGcd < 2) {
        calculated.push(aux)
        aux = -1
        break
      }

      aux = lcmpre(aux, lastValue, currentGcd)
      calculated.pop()
    }

    if (~aux) calculated.push(aux)
  }
  return calculated
}
