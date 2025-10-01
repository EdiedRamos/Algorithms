// * 1518. Water Bottles

function numWaterBottles(numBottles: number, numExchange: number): number {
  let ans = numBottles
  while (numBottles >= numExchange) {
    ans += Math.floor(numBottles / numExchange)
    numBottles =
      (numBottles % numExchange) + Math.floor(numBottles / numExchange)
  }
  return ans
}
