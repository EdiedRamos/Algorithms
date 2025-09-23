// * 165. Compare Version Numbers

function getMissing(n: number): string[] {
  return new Array(n).fill('0')
}

function compareVersion(version1: string, version2: string): number {
  const revisionA = version1.split('.')
  const revisionB = version2.split('.')
  if (revisionA.length < revisionB.length)
    revisionA.push(...getMissing(revisionB.length - revisionA.length))
  if (revisionB.length < revisionA.length)
    revisionB.push(...getMissing(revisionA.length - revisionB.length))
  for (let i = 0; i < revisionA.length; i++) {
    if (+revisionA[i] < +revisionB[i]) return -1
    if (+revisionA[i] > +revisionB[i]) return 1
  }
  return 0
}
