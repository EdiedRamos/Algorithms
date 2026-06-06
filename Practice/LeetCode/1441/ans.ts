// 1441. Build an Array With Stack Operations

function buildArray(target: number[], n: number): string[] {
  const operations: string[] = [];
  for (let i = 0; i < target.length; i++) {
    let distance = 0;
    if (i === 0) {
      distance = target[i] - 1;
    } else {
      distance = target[i] - target[i - 1] - 1;
    }
    while (distance--) {
      operations.push("Push");
      operations.push("Pop");
    }
    operations.push("Push");
  }
  return operations;
}
