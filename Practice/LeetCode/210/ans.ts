// 210. Course Schedule II

function findOrder(numCourses: number, prerequisites: number[][]): number[] {
  const previousTasks: number[] = Array(numCourses).fill(0);
  const graph: number[][] = Array.from({ length: numCourses }).map(() => []);
  const path: number[] = [];

  for (const [a, b] of prerequisites) {
    graph[b].push(a);
    previousTasks[a]++;
  }

  const queue: number[] = [];
  for (let i = 0; i < numCourses; i++) {
    if (!previousTasks[i]) queue.push(i);
  }

  while (queue.length) {
    const current = queue.shift();
    if (current === undefined) continue;
    path.push(current);
    for (const neigh of graph[current]) {
      previousTasks[neigh]--;
      if (!previousTasks[neigh]) {
        queue.push(neigh);
      }
    }
  }

  return path.length === numCourses ? path : [];
}
