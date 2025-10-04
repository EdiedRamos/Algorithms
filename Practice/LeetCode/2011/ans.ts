// * 2011. Final Value of Variable After Performing Operations

function finalValueAfterOperations(operations: string[]): number {
  let ans = 0
  for (const op of operations) {
    if (op[1] === '+') ans++
    else ans--
  }
  return ans
}
