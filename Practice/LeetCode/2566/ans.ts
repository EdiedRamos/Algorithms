// * 2566. Maximum Difference by Remapping a Digit

function minMaxDifference(num: number): number {
  const numAsStr = String(num)

  const maxTarget = [...numAsStr].findIndex((digit) => Number(digit) !== 9)
  const minFirstDigit = numAsStr[0]

  let maxNumber = num
  if (maxTarget !== -1) {
    const targetValue = numAsStr[maxTarget]
    maxNumber = Number(numAsStr.replaceAll(targetValue, '9'))
  }

  const minNumber = Number(numAsStr.replaceAll(minFirstDigit, '0'))

  return maxNumber - minNumber
}
