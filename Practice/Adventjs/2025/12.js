/**
 * @param {string} elf1 - The moves of the first elf
 * @param {string} elf2 - The moves of the second elf
 * @return {number} - The result of the battle
 */
function elfBattle(elf1, elf2) {
  // Code here
  let elf1Hp = 3, elf2Hp = 3
  const relationDamage = {
    AA: [1, 1],
    AB: [0, 0],
    AF: [1, 2],
    BB: [0, 0],
    BA: [0, 0],
    BF: [0, 2],
    FF: [2, 2],
    FA: [2, 1],
    FB: [2, 0]
  }
  for (let i = 0; i < elf1.length; i++) {
    const [damageElf1, damageElf2] = relationDamage[`${elf1[i]}${elf2[i]}`]
    elf1Hp -= damageElf2
    elf2Hp -= damageElf1
    if (elf1Hp <= 0 && elf2Hp <= 0) return 0
    if (elf1Hp <= 0) return 2
    if (elf2Hp <= 0) return 1
  }
  return elf1Hp === elf2Hp ? 0 : elf1Hp < elf2Hp ? 2 : 1
}
