// * Filter the defective gifts

function filterGifts(gifts: string[]): string[] {
  return gifts.filter((gift) => !gift.includes('#'))
}
