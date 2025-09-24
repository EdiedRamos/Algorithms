// * 166. Fraction to Recurring Decimal

function fractionToDecimal(numerator: number, denominator: number): string {
  if (!numerator) return '0'
  let result = ''
  if ((numerator < 0 || denominator < 0) && !(numerator < 0 && denominator < 0))
    result += '-'
  numerator = Math.abs(numerator)
  denominator = Math.abs(denominator)
  result += Math.floor(numerator / denominator)
  let remainder = numerator % denominator
  if (!remainder) return result
  result += '.'
  const remainderPosition: Record<number, number> = {}
  while (remainder) {
    const remainderPreviousPos = remainderPosition[remainder]
    if (remainderPreviousPos) {
      return (
        result.substring(0, remainderPreviousPos) +
        '(' +
        result.substring(remainderPreviousPos) +
        ')'
      )
    }
    remainderPosition[remainder] = result.length
    remainder *= 10
    result += Math.floor(remainder / denominator)
    remainder %= denominator
  }
  return result
}
