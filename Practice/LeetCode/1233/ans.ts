// * 1233. Remove Sub-Folders from the Filesystem

function removeSubfolders(folder: string[]): string[] {
  const answer: string[] = []
  folder.sort()
  for (let i = 0; i < folder.length; i++) {
    const lastFolder = answer[answer.length - 1]
    const currentFolder = folder[i]
    if (
      lastFolder === undefined ||
      !currentFolder.startsWith(lastFolder.concat('/'))
    ) {
      answer.push(currentFolder)
    }
  }
  return answer
}
