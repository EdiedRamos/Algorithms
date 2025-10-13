// * 3612. Process String with Special Operations I

function processStr(s: string): string {
  let result = ''
  for (const char of s) {
    if (/[a-z]/.test(char)) result += char
    if (char === '*' && result.length)
      result = result.substring(0, result.length - 1)
    if (char === '#') result += result
    if (char === '%') result = [...result].reverse().join('')
  }
  return result
}
