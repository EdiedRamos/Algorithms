// * 3100. Water Bottles II

function maxBottlesDrunk(numBottles: number, numExchange: number): number {
  let drunk = numBottles,
    empty = numBottles
  while (empty >= numExchange) {
    drunk++
    empty -= numExchange
    empty++
    numExchange++
  }
  return drunk
}
