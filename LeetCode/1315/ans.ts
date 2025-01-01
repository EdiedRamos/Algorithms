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

type Node = TreeNode | null;

function sumEvenGrandparent(root: Node): number {
  let ans = 0;
  function dfs(node: Node) {
    if (!node) return;
    if (node.val % 2 === 0) {
      if (node.left) {
        if (node.left.left) ans += node.left.left.val;
        if (node.left.right) ans += node.left.right.val;
      }
      if (node.right) {
        if (node.right.left) ans += node.right.left.val;
        if (node.right.right) ans += node.right.right.val;
      }
    }
    dfs(node.left);
    dfs(node.right);
  }
  dfs(root);
  return ans;
};
