// * 2169. Count Operations to Obtain Zero

function countOperations(num1: number, num2: number): number {
  let operations = 0
  while (num1 !== 0 && num2 !== 0) {
    if (num1 >= num2) num1 -= num2
    else num2 -= num1
    operations++
  }
  return operations
}
