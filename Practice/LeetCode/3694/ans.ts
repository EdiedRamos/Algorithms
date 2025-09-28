// * 3694. Distinct Points Reachable After Substring Removal

function distinctPoints(s: string, k: number): number {
  const moveX = {
    U: 0,
    D: 0,
    L: -1,
    R: 1,
  }
  const moveY = {
    U: 1,
    D: -1,
    L: 0,
    R: 0,
  }
  const distinct: Set<string> = new Set()
  const calculateBefore = Array.from({ length: s.length + 5 }).map(() => [0, 0])
  const calculateAfter = Array.from({ length: s.length + 5 }).map(() => [0, 0])

  for (let i = 0; i < s.length; i++) {
    const [beforeX, beforeY] = calculateBefore[i]
    calculateBefore[i + 1] = [beforeX + moveX[s[i]], beforeY + moveY[s[i]]]
  }

  for (let i = s.length - 1; i >= 0; i--) {
    const [afterX, afterY] = calculateAfter[i + 1]
    calculateAfter[i] = [afterX + moveX[s[i]], afterY + moveY[s[i]]]
  }

  // console.log({ calculateBefore, calculateAfter });

  for (let i = 0; i <= s.length - k; i++) {
    const [beforeX, beforeY] = calculateBefore[i]
    const [afterX, afterY] = calculateAfter[i + k]
    distinct.add(`${beforeX + afterX}~${beforeY + afterY}`)
  }

  return distinct.size
}
