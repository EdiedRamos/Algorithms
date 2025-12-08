// * Decorating the tree

function drawTree(height: number, ornament: string, frequency: number): string {
  let tree = ''
  let currentWidth = 1
  let decorationIndex = 1
  for (let i = 0; i < height; i++) {
    tree += ' '.repeat(height - i - 1)
    for (let k = 0; k < currentWidth; k++) {
      if (decorationIndex >= frequency && decorationIndex % frequency === 0)
        tree += ornament
      else tree += '*'
      decorationIndex++
    }
    currentWidth += 2
    tree += '\n'
  }
  tree += ' '.repeat(height - 1)
  tree += '#'
  return tree
}

console.log(drawTree(5, 'o', 2))
//     *
//    o*o
//   *o*o*
//  o*o*o*o
// *o*o*o*o*
//     #

console.log(drawTree(3, '@', 3))
//   *
//  *@*
// *@**@
//   #

console.log(drawTree(4, '+', 1))
//    +
//   +++
//  +++++
// +++++++
//    #
