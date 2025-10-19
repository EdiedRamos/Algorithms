function extractAttributes(element) {
  const attributes = []
  let isOpenAttribute = false
  let gettingValue = false
  let key = '',
    value = ''
  for (const char of element) {
    if (char === '"') {
      isOpenAttribute = !isOpenAttribute
    } else if (char === ' ' || char === '>') {
      if (isOpenAttribute) {
        value += char
        continue
      }
      if (key.length && value.length) {
        attributes.push(`${key}, ${value}`)
      }
      key = ''
      value = ''
      gettingValue = false
    } else if (char === '=') {
      gettingValue = true
    } else {
      if (gettingValue) value += char
      else key += char
    }
  }

  return attributes
}

const test1 = extractAttributes('<span class="red"></span>')
const test2 = extractAttributes('<meta charset="UTF-8" />')
const test3 = extractAttributes('<p>Lorem ipsum dolor sit amet</p>')
const test4 = extractAttributes(
  '<input name="email" type="email" required="true" />'
)
const test5 = extractAttributes(
  '<button id="submit" class="btn btn-primary">Submit</button>'
)

console.log('Test 1', test1)
console.log('Test 2', test2)
console.log('Test 3', test3)
console.log('Test 4', test4)
console.log('Test 5', test5)
