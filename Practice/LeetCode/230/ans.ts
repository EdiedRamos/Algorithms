// * 230. Kth Smallest Element in a BST

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

function kthSmallest(root: TreeNode | null, k: number): number {
  const sorted: number[] = []
  const inOrder = (root: TreeNode | null) => {
    if (!root) return
    inOrder(root.left)
    sorted.push(root.val)
    inOrder(root.right)
  }
  inOrder(root)
  return sorted[k - 1]
}
