// * The countdown to take off

type ElfDateTime =
  `${number}*${number}*${number}@${number}|${number}|${number} NP`

function timeUntilTakeOff(
  fromTime: ElfDateTime,
  takeOffTime: ElfDateTime
): number {
  function transformToDate(format: ElfDateTime): Date {
    const initialPartitions = format.split('@')
    let [year, month, day] = initialPartitions[0].split('*')
    let [hour, minutes, seconds] = initialPartitions[1].split(' ')[0].split('|')
    return new Date(`${year}-${month}-${day}T${hour}:${minutes}:${seconds}Z`)
  }

  const from = transformToDate(fromTime)
  const take = transformToDate(takeOffTime)
  const diff = Math.floor((take.getTime() - from.getTime()) / 1000)
  return diff
}

const takeoff = '2025*12*25@00|00|00 NP'

// from December 24, 2025, 23:59:30, 30 seconds before takeoff
console.assert(timeUntilTakeOff('2025*12*24@23|59|30 NP', takeoff) === 30)
// 30

// exactly at takeoff time
console.assert(timeUntilTakeOff('2025*12*25@00|00|00 NP', takeoff) === 0)
// 0

// 12 seconds after takeoff
console.assert(timeUntilTakeOff('2025*12*25@00|00|12 NP', takeoff) === -12)
// -12
