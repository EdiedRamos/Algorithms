// * 771. Jewels and Stones

function numJewelsInStones(jewels: string, stones: string): number {
  let ans = 0
  for (const stone of stones) {
    if (jewels.includes(stone)) {
      ans++
    }
  }
  return ans
}
