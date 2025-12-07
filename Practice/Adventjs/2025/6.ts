// * Matching gloves

type Glove = { hand: 'L' | 'R'; color: string }

function matchGloves(gloves: Glove[]): string[] {
  // Code here
  const answer: string[] = []
  const used: boolean[] = Array(gloves.length).fill(false)
  for (let i = 0; i < gloves.length; i++) {
    for (let j = i + 1; j < gloves.length; j++) {
      if (
        !used[i] &&
        !used[j] &&
        gloves[i].color === gloves[j].color &&
        gloves[i].hand !== gloves[j].hand
      ) {
        answer.push(gloves[i].color)
        used[i] = true
        used[j] = true
      }
    }
  }
  return answer
}

const gloves = [
  { hand: 'L', color: 'red' },
  { hand: 'R', color: 'red' },
  { hand: 'R', color: 'green' },
  { hand: 'L', color: 'blue' },
  { hand: 'L', color: 'green' },
]

console.log(matchGloves(gloves))
// ["red", "green"]

const gloves2 = [
  { hand: 'L', color: 'gold' },
  { hand: 'R', color: 'gold' },
  { hand: 'L', color: 'gold' },
  { hand: 'L', color: 'gold' },
  { hand: 'R', color: 'gold' },
]

console.log(matchGloves(gloves2))
// ["gold", "gold"]

const gloves3 = [
  { hand: 'L', color: 'red' },
  { hand: 'R', color: 'green' },
  { hand: 'L', color: 'blue' },
]

console.log(matchGloves(gloves3))
// []
