// * 98. Validate Binary Search Tree

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

function isValidBST(root: TreeNode | null): boolean {
  const values: number[] = []
  const inOrder = (root: TreeNode | null): void => {
    if (!root) return
    inOrder(root.left)
    values.push(root.val)
    inOrder(root.right)
  }
  inOrder(root)
  for (let i = 1; i < values.length; i++)
    if (values[i] <= values[i - 1]) return false
  return true
}
