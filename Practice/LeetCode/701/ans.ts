// * 701. Insert into a Binary Search Tree

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

function buildNode(val: number): TreeNode {
  return {
    val,
    left: null,
    right: null,
  }
}

function insertIntoBST(root: TreeNode | null, val: number): TreeNode | null {
  if (!root) return buildNode(val)
  if (val < root.val) {
    if (root.left) insertIntoBST(root.left, val)
    else root.left = buildNode(val)
  } else {
    if (root.right) insertIntoBST(root.right, val)
    else root.right = buildNode(val)
  }
  return root
}
