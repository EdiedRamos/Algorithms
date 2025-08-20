// * 8. String to Integer (atoi)

function myAtoi(s: string): number {
  try {
    const ans = parseInt(s)
    if (isNaN(ans)) return 0
    if (ans > 2147483647) return 2147483647
    if (ans < -2147483648) return -2147483648
    return ans
  } catch {
    return 0
  }
}
