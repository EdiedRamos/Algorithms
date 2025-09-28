// * 3692. Majority Frequency Characters

function majorityFrequencyGroup(s: string): string {
  const frecuency: Record<string, number> = {}
  for (const char of s) {
    frecuency[char] = (frecuency[char] ?? 0) + 1
  }
  const group: Record<string, string> = {}
  let maxFrecuency = -1,
    answer = ''
  for (const [key, value] of Object.entries(frecuency)) {
    group[value] = (group[value] ?? '') + key
  }
  for (const [key, value] of Object.entries(group)) {
    if (
      value.length > answer.length ||
      (value.length === answer.length && +key > maxFrecuency)
    ) {
      answer = value
      maxFrecuency = +key
    }
  }
  return answer
}
