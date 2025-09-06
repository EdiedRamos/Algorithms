// * 1372. Longest ZigZag Path in a Binary Tree

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

let currentIndex = 0
const memo: Record<number, { left: number; right: number }> = {}

function dfs(root: TreeNode | null, toTheLeft: boolean): number {
  if (!root) return 0
  const key = toTheLeft ? 'left' : 'right'
  if (~memo[root.val][key]) return memo[root.val][key]
  // console.log(root.val)
  if (toTheLeft) return (memo[root.val][key] = dfs(root.left, !toTheLeft) + 1)
  return (memo[root.val][key] = dfs(root.right, !toTheLeft) + 1)
}

function configureNode(root: TreeNode | null) {
  if (!root) return
  root.val = currentIndex++
  memo[root.val] = {
    left: -1,
    right: -1,
  }
  configureNode(root.left)
  configureNode(root.right)
}

function longestZigZag(root: TreeNode | null): number {
  let maxi = 0

  configureNode(root)

  const validateAllNodes = (root: TreeNode | null) => {
    if (!root) return

    const ansLeft = dfs(root, true)
    const ansRight = dfs(root, false)
    maxi = Math.max(maxi, Math.max(ansLeft, ansRight) - 1)

    if (root.left) validateAllNodes(root.left)
    if (root.right) validateAllNodes(root.right)
  }

  validateAllNodes(root)

  return maxi
}
