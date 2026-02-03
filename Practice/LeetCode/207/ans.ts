// 207. Course Schedule

function canFinish(numCourses: number, prerequisites: number[][]): boolean {
  const previousTasks: number[] = Array(numCourses).fill(0);
  const graph: number[][] = Array.from({ length: numCourses }).map(() => []);
  let tasksDone = 0;

  const dfs = (node: number) => {
    if (previousTasks[node] !== 0) return;
    previousTasks[node]--;
    tasksDone++;
    for (const neigh of graph[node]) {
      previousTasks[neigh]--;
      dfs(neigh);
    }
  };

  for (const [a, b] of prerequisites) {
    graph[b].push(a);
    previousTasks[a]++;
  }

  for (let i = 0; i < numCourses; i++) {
    if (!previousTasks[i]) {
      dfs(i);
    }
  }

  return tasksDone === numCourses;
}
