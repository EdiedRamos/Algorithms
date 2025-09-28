// * 3697. Compute Decimal Representation

function decimalRepresentation(n: number): number[] {
  const result: number[] = []
  const nstr = String(n)
  for (let i = 0; i < nstr.length; i++) {
    const length = nstr.length - i - 1
    if (nstr[i] !== '0') {
      result.push(+nstr[i] * Math.pow(10, length))
    }
    // console.log({ length })
  }
  return result
}
