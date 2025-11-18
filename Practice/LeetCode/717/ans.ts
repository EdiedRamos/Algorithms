// * 717. 1-bit and 2-bit Characters

function isOneBitCharacter(bits: number[]): boolean {
  for (let i = 0; i < bits.length; ) {
    if (i === bits.length - 1) return true
    if (bits[i]) i += 2
    else i++
  }
  return false
}
