// * 133. Clone Graph

/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     neighbors: _Node[]
 *
 *     constructor(val?: number, neighbors?: _Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.neighbors = (neighbors===undefined ? [] : neighbors)
 *     }
 * }
 *
 */

function cloneGraph(node: _Node | null): _Node | null {
  if (!node) return node

  const visited = new Set<number>()
  const queue: _Node[] = [node]
  const adja: Record<number, number[]> = { 1: [] }
  while (queue.length) {
    const current = queue.pop()
    if (!current) continue
    if (visited.has(current.val)) continue
    visited.add(current.val)
    for (const neighbor of current.neighbors) {
      if (!adja[current.val]) adja[current.val] = []
      adja[current.val].push(neighbor.val)
      queue.push(neighbor)
    }
  }
  const info: Record<number, _Node | null> = {}
  for (const node of Object.keys(adja)) {
    info[+node] = new _Node(+node, [])
  }
  for (const [val, children] of Object.entries(adja)) {
    for (const child of children) {
      info[+val].neighbors.push(info[child])
    }
  }
  return info[1]
}
