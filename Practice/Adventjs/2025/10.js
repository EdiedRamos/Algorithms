// * Depth of christmas magic

/**
 * @param {string} s - The string to check
 * @returns {number} The maximum depth of the magic
 */
function maxDepth(s) {
  let open = 0,
    maxNested = 0,
    currentNesting = 0
  for (const c of s) {
    if (c === '[') {
      open++
      currentNesting++
    }
    if (c === ']') {
      currentNesting--
      if (open === 0) return -1
      open--
    }
    maxNested = Math.max(maxNested, currentNesting)
  }
  return open === 0 && currentNesting === 0 ? maxNested : -1
}

const test1 = maxDepth('[]')
console.assert(test1 === 1, `Test 1: Answer is 1, ${test1} was found`) // -> 1

const test2 = maxDepth('[[]]')
console.assert(test2 === 2, `Test 2: Answer is 2, ${test2} was found`) // -> 2

const test3 = maxDepth('[][]')
console.assert(test3 === 1, `Test 3: Answer is 1, ${test3} was found`) // -> 1

const test4 = maxDepth('[[][]]')
console.assert(test4 === 2, `Test 4: Answer is 2, ${test4} was found`) // -> 2

const test5 = maxDepth('[[[]]]')
console.assert(test5 === 3, `Test 5: Answer is 3, ${test5} was found`) // -> 3

const test6 = maxDepth('[][[]][]')
console.assert(test6 === 2, `Test 6: Answer is 2, ${test6} was found`) // -> 2

const test7 = maxDepth('][')
console.assert(test7 === -1, `Test 7: Answer is -1, ${test7} was found`) // -> -1 (closes before opening)

const test8 = maxDepth('[[[')
console.assert(test8 === -1, `Test 8: Answer is -1, ${test8} was found`) // -> -1 (missing closing brackets)

const test9 = maxDepth('[]]]')
console.assert(test9 === -1, `Test 9: Answer is -1, ${test9} was found`) // -> -1 (extra closing brackets)

const test10 = maxDepth('[][][')
console.assert(test10 === -1, `Test 10: Answer is -1, ${test10} was found`) // -> -1 (one remains unclosed)
