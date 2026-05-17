// 1306. Jump Game III

function canReach(arr: number[], start: number): boolean {
  const visited = new Set<number>();
  const pending: number[] = [start];
  let last = 0;
  while (last < pending.length) {
    const current = pending[last++];
    if (!arr[current]) {
      return true;
    }
    visited.add(current);
    const left = current - arr[current];
    const right = current + arr[current];
    if (left >= 0 && !visited.has(left)) {
      pending.push(left);
    }
    if (right < arr.length && !visited.has(right)) {
      pending.push(right);
    }
  }
  return false;
}
