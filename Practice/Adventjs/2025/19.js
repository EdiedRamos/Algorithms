/**
 * Santa's secret journey
 * @param {string[][]} routes - Array of [origin, destination] pairs
 * @returns {string[]} The reconstructed route
 */
function revealSantaRoute(routes) {
  // Code here
  const completePath = []
  const connections = {}
  for (const [origin, destination] of routes) {
    connections[origin] = destination
  }
  let currentDestination = routes[0][1]
  completePath.push(...[routes[0][0], currentDestination])
  while (connections[currentDestination]) {
    const nextDestination = connections[currentDestination]
    completePath.push(nextDestination)
    currentDestination = nextDestination
  }
  return completePath
}
