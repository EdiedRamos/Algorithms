// * 860. Lemonade Change

function lemonadeChange(bills: number[]): boolean {
  let changeSaved: Record<number, number> = {
    5: 0,
    10: 0,
  }
  for (const bill of bills) {
    let change = bill - 5
    changeSaved[bill]++
    // console.log({ change, changeSaved })
    while (change >= 10 && changeSaved[10]) {
      change -= 10
      changeSaved[10]--
    }
    while (change >= 5 && changeSaved[5]) {
      change -= 5
      changeSaved[5]--
    }
    if (change) return false
  }
  return true
}

/**
 * 5 => 0
 * 10 => 5
 * 20 => 15
 */
