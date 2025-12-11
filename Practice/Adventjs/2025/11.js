/**
 * @param {string[]} warehouse - The warehouse layout
 * @returns {number} The count of unwatched gifts
 */
function findUnsafeGifts(warehouse) {
  // Code here
  let count = 0
  for (let i = 0; i < warehouse.length; i++) {
    for (let j = 0; j < warehouse[i].length; j++) {
      let isProtected = false
      
      if (i - 1 >= 0 && warehouse[i - 1][j] === '#') isProtected = true
      if (i + 1 < warehouse.length && warehouse[i + 1][j] === '#') isProtected = true
      if (j - 1 >= 0 && warehouse[i][j - 1] === '#') isProtected = true
      if (j + 1 < warehouse[i].length && warehouse[i][j + 1] === '#') isProtected = true 

      if (warehouse[i][j] === '*' && !isProtected) count++
    }
  }
  return count
}
