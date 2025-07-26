// * 959. Regions Cut By Slashes

type Connection = {
  first: number
  second?: number
}

type Graph = Map<number, number[]>

const MASK = {
  EMPTY: ' ',
  DIAG1: '/',
  DIAG2: '\\',
}

const CONNECTIONS = {
  [MASK.EMPTY]: {
    rightConnectionNode(connection: Connection, type: string): number {
      if (connection.second === undefined) return connection.first
      if (type === '\\') return connection.second
      return connection.first
    },
    bottomConnectionNode(connection: Connection): number {
      return connection.first
    },
  },
  [MASK.DIAG1]: {
    rightConnectionNode(connection: Connection, type: string): number {
      if (connection.second === undefined) return connection.first
      if (type === MASK.DIAG2) return connection.second
      return connection.first
    },
    bottomConnectionNode(connection: Connection): number {
      return connection.first
    },
  },
  [MASK.DIAG2]: {
    rightConnectionNode(connection: Connection, type: string): number {
      if (connection.second === undefined) return connection.first
      if (type === MASK.DIAG2) return connection.second
      return connection.first
    },
    bottomConnectionNode(connection: Connection): number {
      return connection.first
    },
  },
}

function getRelationIndex(i: number, j: number, n: number): number {
  return n * i + j
}

function addNode(graph: Graph, start: number, end: number) {
  const previousStart = graph.get(start) ?? []
  const previousEnd = graph.get(end) ?? []
  graph.set(start, [...previousStart, end])
  graph.set(end, [...previousEnd, start])
}

function regionsBySlashes(grid: string[]): number {
  const positionIndex: Map<number, Connection> = new Map()
  let globalIndex = 0
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      if (grid[i][j] === MASK.EMPTY) {
        positionIndex.set(positionIndex.size, { first: globalIndex })
        globalIndex++
      } else {
        positionIndex.set(positionIndex.size, {
          first: globalIndex,
          second: globalIndex + 1,
        })
        globalIndex += 2
      }
    }
  }
  // console.log({ positionIndex })
  const graph: Graph = new Map()
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      const currentIndex = getRelationIndex(i, j, grid.length)
      const currentPosition = positionIndex.get(currentIndex)
      if (!currentPosition) {
        // console.log('damn', currentPosition, currentIndex, grid[i][j])
        continue
      }
      const right = grid[i]?.[j + 1]
      const rightConnection = positionIndex.get(
        getRelationIndex(i, j + 1, grid.length)
      )
      const bottom = grid[i + 1]?.[j]
      const bottomConnection = positionIndex.get(
        getRelationIndex(i + 1, j, grid.length)
      )
      // console.log({ current: grid[i][j], right, bottom })
      if (grid[i][j] === MASK.EMPTY) {
        if (right !== undefined && rightConnection) {
          const rightIndex = CONNECTIONS[MASK.EMPTY].rightConnectionNode(
            rightConnection,
            right
          )
          addNode(graph, currentPosition.first, rightIndex)
        }
        if (bottom !== undefined && bottomConnection) {
          const bottomIndex =
            CONNECTIONS[MASK.EMPTY].bottomConnectionNode(bottomConnection)
          addNode(graph, currentPosition.first, bottomIndex)
        }
      }
      if (grid[i][j] === MASK.DIAG1 && currentPosition.second !== undefined) {
        if (right !== undefined && rightConnection) {
          const rightIndex = CONNECTIONS[MASK.DIAG1].rightConnectionNode(
            rightConnection,
            right
          )
          addNode(graph, currentPosition.second, rightIndex)
        }
        if (bottom !== undefined && bottomConnection) {
          const bottomIndex =
            CONNECTIONS[MASK.DIAG1].bottomConnectionNode(bottomConnection)
          addNode(graph, currentPosition.second, bottomIndex)
        }
      }
      if (grid[i][j] === MASK.DIAG2) {
        if (right !== undefined && rightConnection) {
          const rightIndex = CONNECTIONS[MASK.DIAG2].rightConnectionNode(
            rightConnection,
            right
          )
          addNode(graph, currentPosition.first, rightIndex)
        }
        if (
          bottom !== undefined &&
          bottomConnection &&
          currentPosition.second !== undefined
        ) {
          const bottomIndex =
            CONNECTIONS[MASK.DIAG2].bottomConnectionNode(bottomConnection)
          addNode(graph, currentPosition.second, bottomIndex)
        }
      }
    }
  }
  for (let i = 0; i < globalIndex; i++) {
    if (!graph.has(i)) {
      graph.set(i, [])
    }
  }
  const visited: boolean[] = Array.from({ length: globalIndex }).map(
    () => false
  )
  const dfs = (node: number) => {
    if (visited[node]) return
    visited[node] = true
    const neigh = graph.get(node)
    neigh?.forEach((n) => {
      dfs(n)
    })
  }
  let regions = 0
  for (let i = 0; i < globalIndex; i++) {
    if (!visited[i]) {
      regions++
      dfs(i)
    }
  }
  // console.log({ graph })
  return regions
}
