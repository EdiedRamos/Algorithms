// * 637. Average of Levels in Binary Tree

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function averageOfLevels(root: TreeNode | null): number[] {
  const values: Record<number, number[]> = {}

  const dfs = (node: TreeNode | null, level: number): void => {
    if (!node) return

    if (!values[level]) values[level] = []
    values[level].push(node.val)

    dfs(node.left, level + 1)
    dfs(node.right, level + 1)
  }

  dfs(root, 0)

  return Object.values(values).map(
    (values) => values.reduce((a, b) => a + b, 0) / values.length
  )
}
