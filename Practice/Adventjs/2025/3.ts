// * Help the intern

function drawGift(size: number, symbol: string): string {
  if (size < 2) return ''
  let answer = ''
  answer += symbol.repeat(size) + '\n'
  for (let i = 0; i < size - 2; i++)
    answer += symbol
      .concat(' '.repeat(size - 2))
      .concat(symbol)
      .concat('\n')
  answer += symbol.repeat(size)
  return answer
}

const g1 = drawGift(4, '*')
console.log(g1)
/*
 ****
 *  *
 *  *
 ****
 */

const g2 = drawGift(3, '#')
console.log(g2)
/*
###
# #
###
*/

const g3 = drawGift(2, '-')
console.log(g3)
/*
--
--
*/

const g4 = drawGift(1, '+')
console.log(g4)
// ""  poor intern…