// * 559. Maximum Depth of N-ary Tree

/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     children: _Node[]
 *
 *     constructor(val?: number, children?: _Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.children = (children===undefined ? [] : children)
 *     }
 * }
 */

function dfs(node: _Node, level: number, maximum: number): number {
  if (!node) return -Infinity
  if (!node.children.length) return Math.max(maximum, level + 1)
  let maximumChild = -Infinity
  for (const child of node.children) {
    maximumChild = Math.max(maximumChild, dfs(child, level + 1, maximum))
  }
  return maximumChild
}

function maxDepth(root: _Node | null): number {
  if (!root) return 0
  return dfs(root, 0, -Infinity)
}
