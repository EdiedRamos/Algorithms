// * Manufacture the toys

function manufactureGifts(
  giftsToProduce: Array<{ toy: string; quantity: number }>
): string[] {
  let answer: string[] = []
  for (const gift of giftsToProduce) {
    if (typeof gift.quantity === 'number' && gift.quantity > 0)
      answer = answer.concat(Array(gift.quantity).fill(gift.toy))
  }
  return answer
}
