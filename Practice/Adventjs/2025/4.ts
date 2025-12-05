// * Decipher the santa pin

function decodeSantaPin(code: string): string | null {
  let decoded = ''
  let repeatLast = false
  let value = 0
  for (const char of code) {
    if (char === '[') {
      value = 0
    } else if (char === ']') {
      if (repeatLast) {
        if (decoded.length === 0) return null
        decoded += decoded[decoded.length - 1]
      } else decoded += String(value)
      repeatLast = false
    } else if (/[0123456789]/.test(char)) {
      value = +char
    } else if (char === '<') {
      repeatLast = true
    } else if (char === '+') {
      value++
      if (value > 9) value = 0
    } else if (char === '-') {
      value--
      if (value < 0) value = 9
    }
  }
  return decoded.length < 4 ? null : decoded
}
