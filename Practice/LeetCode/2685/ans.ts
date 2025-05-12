// * 2685. Count the Number of Complete Components

function countCompleteComponents(n: number, edges: number[][]): number {
  const relationMatrix: boolean[][] = Array.from({ length: n }).map(() =>
    Array.from({ length: n }).map(() => false)
  );
  const visitedMatrix: boolean[] = Array.from({ length: n }).map(() => false);
  for (const relation of edges) {
    const [x, y] = relation;
    relationMatrix[x][y] = true;
    relationMatrix[y][x] = true;
  }
  const components: number[][] = [];
  for (let currentNode = 0; currentNode < n; currentNode++) {
    if (visitedMatrix[currentNode]) continue;
    const pendingNodes: number[] = [currentNode];
    const component: number[] = [];
    while (pendingNodes.length) {
      const node = pendingNodes.pop();
      if (node === undefined) continue;
      if (!visitedMatrix[node]) {
        component.push(node);
      }
      visitedMatrix[node] = true;
      for (let i = 0; i < n; i++) {
        if (!visitedMatrix[i] && relationMatrix[node][i]) {
          pendingNodes.push(i);
        }
      }
    }
    components.push(component);
  }
  let completeComponents: number = 0;
  for (const component of components) {
    let isComplete = true;
    for (let i = 0; i < component.length; i++) {
      for (let j = i + 1; j < component.length; j++) {
        if (!relationMatrix[component[i]][component[j]]) {
          isComplete = false;
        }
      }
    }
    completeComponents += isComplete ? 1 : 0;
  }
  return completeComponents;
}
