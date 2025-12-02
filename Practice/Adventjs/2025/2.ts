// * Manufacture the toys

function manufactureGifts(
  giftsToProduce: Array<{ toy: string; quantity: number }>
): string[] {
  const answer: string[] = []
  for (const gift of giftsToProduce) {
    if (typeof gift.quantity !== 'number' || gift.quantity < 1) continue
    for (let i = 0; i < gift.quantity; i++) answer.push(gift.toy)
  }
  return answer
}
