// * Drawing tables

type Data = Array<Record<string, string | number>>
type SortBy = string

function drawTable(data: Data, sortBy: SortBy): string {
  data.sort((a, b) => {
    const valueA = a[sortBy] ?? ''
    const valueB = b[sortBy] ?? ''

    if (typeof valueA === 'number' && typeof valueB === 'number') {
      return valueA - valueB
    }

    return String(valueA).localeCompare(String(valueB))
  })

  const columnsWidth = data.reduce<number[]>((acc, info) => {
    Object.values(info).forEach((val, i) => {
      const length = String(val).length
      acc[i] = acc[i] ? Math.max(acc[i], length) : length
    })
    return acc
  }, [])

  const addSeparator = () =>
    '+' + columnsWidth.map((w) => '-'.repeat(w + 2)).join('+') + '+'

  let table = ''

  table += addSeparator() + '\n'
  const header = columnsWidth
    .map((w, i) => ` ${String.fromCharCode(65 + i)} `.padEnd(w + 2, ' '))
    .join('|')
  table += `|${header}|\n`
  table += addSeparator() + '\n'
  for (const info of data) {
    const row = columnsWidth
      .map((w, i) => ` ${String(info[Object.keys(info)[i]]).padEnd(w, ' ')} `)
      .join('|')
    table += `|${row}|\n`
  }
  table += addSeparator()
  return table
}
