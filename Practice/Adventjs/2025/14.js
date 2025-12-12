/**
 * @param {object} workshop - A representation of the workshop
 * @param {string|number|boolean} gift - The gift to find
 * @returns {string[]} The path to the gift
 */
function findGiftPath(workshop, gift) {
  let resultPath = []

  const search = (content, currentPath) => {
    if (['string', 'number', 'boolean'].includes(typeof content)) {
      if (content === gift) {
        resultPath = [...currentPath]
      }
      return
    }

    for (const key of Object.keys(content)) {
      currentPath.push(key)
      search(content[key], currentPath)
      currentPath.pop()
    }
  }
  search(workshop, [])

  return resultPath
}
