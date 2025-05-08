// * 797. All Paths From Source to Target

interface PendingNode {
  index: number;
  path: number[];
}

function allPathsSourceTarget(graph: number[][]): number[][] {
  const pendingNodes: PendingNode[] = [];
  const allPaths: number[][] = [];

  pendingNodes.push({
    index: 0,
    path: [0],
  });

  while (pendingNodes.length) {
    const currentNode: PendingNode = pendingNodes.pop()!;
    if (currentNode.index === graph.length - 1) {
      allPaths.push(currentNode.path);
    }
    for (const neigh of graph[currentNode.index]) {
      pendingNodes.push({
        index: neigh,
        path: [...currentNode.path, neigh],
      });
    }
  }

  return allPaths;
}
