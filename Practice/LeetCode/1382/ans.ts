// * 1382. Balance a Binary Search Tree

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

function buildBst(
  data: number[],
  left: number,
  right: number
): TreeNode | null {
  if (left > right) return null
  const middle = (left + right) >> 1
  const leftSubtree: TreeNode | null = buildBst(data, left, middle - 1)
  const rightSubtree: TreeNode | null = buildBst(data, middle + 1, right)
  return {
    val: data[middle],
    left: leftSubtree,
    right: rightSubtree,
  }
}

function balanceBST(root: TreeNode | null): TreeNode | null {
  const sorted: number[] = []
  const inOrder = (root: TreeNode | null) => {
    if (root === null) return
    if (root.left) inOrder(root.left)
    sorted.push(root.val)
    if (root.right) inOrder(root.right)
  }
  inOrder(root)
  return buildBst(sorted, 0, sorted.length - 1)
}
