// * 111. Minimum Depth of Binary Tree

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

type TNode = TreeNode | null

function dfs(node: TNode, level: number, minimum: number): number {
  if (!node) return Infinity
  if (!node.left && !node.right) return Math.min(minimum, level + 1)
  const minimumLeft = dfs(node.left, level + 1, minimum)
  const minimumRight = dfs(node.right, level + 1, minimum)
  return Math.min(minimumLeft, minimumRight)
}

function minDepth(root: TNode): number {
  if (!root) return 0
  return dfs(root, 0, Infinity)
}
