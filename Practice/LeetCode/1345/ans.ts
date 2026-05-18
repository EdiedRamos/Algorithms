function minJumps(arr: number[]): number {
  const n = arr.length;

  const jumps: Record<number, number[]> = {};
  for (let i = 0; i < n; i++) {
    if (jumps[arr[i]] === undefined) jumps[arr[i]] = [];
    jumps[arr[i]].push(i);
  }

  const visited: boolean[] = new Array(n).fill(false);
  const distance: number[] = new Array(n).fill(n + 5);
  const pending: number[] = [0];
  let pendingHead = 0;
  distance[0] = 0;

  while (pendingHead < pending.length) {
    const current = pending[pendingHead++];

    if (current === n - 1) {
      return distance[current];
    }

    const left = current - 1;
    const right = current + 1;

    if (left >= 0 && !visited[left]) {
      pending.push(left);
      distance[left] = Math.min(distance[left], distance[current] + 1);
      visited[left] = true;
    }
    if (right < n && !visited[right]) {
      pending.push(right);
      distance[right] = Math.min(distance[right], distance[current] + 1);
      visited[right] = true;
    }

    for (const jump of jumps[arr[current]]) {
      if (jump !== current && !visited[jump]) {
        pending.push(jump);
        distance[jump] = Math.min(distance[jump], distance[current] + 1);
        visited[jump] = true;
      }
    }
    // ! This is really important to avoid TLE or JavaScript heap out of memory errors.
    // * Once you have processed a specific value, clear its entries in the jumps object to avoid redundant searches.
    // * Without this line, the time complexity would degrade to O(n²) and cause excessive memory usage.
    jumps[arr[current]] = [];
  }

  return -1;
}
