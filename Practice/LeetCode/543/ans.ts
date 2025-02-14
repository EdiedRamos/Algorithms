// 543. Diameter of Binary Tree
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

let area = 0;

function traverse(root: TreeNode | null) {
  if (!root) return 0;
  const betterLeft = traverse(root.left);
  const betterRight = traverse(root.right);
  area = Math.max(area, betterLeft + betterRight);
  return Math.max(betterLeft, betterRight) + 1;
}

function diameterOfBinaryTree(root: TreeNode | null): number {
  area = 0;
  traverse(root);
  return area;
};
