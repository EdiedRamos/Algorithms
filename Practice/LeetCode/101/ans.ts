// * 101. Symmetric Tree

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

function dfs(leftNode: TNode, rightNode: TNode): boolean {
  if (!leftNode && !rightNode) return true
  if (!leftNode || !rightNode) return false
  if (leftNode.val !== rightNode.val) return false
  return (
    dfs(leftNode.left, rightNode.right) && dfs(leftNode.right, rightNode.left)
  )
}

function isSymmetric(root: TNode): boolean {
  return dfs(root.left, root.right)
}
