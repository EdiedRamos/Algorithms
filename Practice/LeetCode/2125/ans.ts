// * 2125. Number of Laser Beams in a Bank

function numberOfBeams(bank: string[]): number {
  let result = 0,
    aux = 0
  for (let i = 0; i < bank.length; i++) {
    let devices = 0
    for (let j = 0; j < bank[i].length; j++) {
      if (bank[i][j] === '1') devices++
    }
    if (devices > 0) {
      result += devices * aux
      aux = devices
    }
  }
  return result
}
