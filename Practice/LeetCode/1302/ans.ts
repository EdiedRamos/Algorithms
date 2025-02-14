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

function deepestLeavesSum(root: Node): number {
  let ans = 0;
  let maxLevel = 0;
  function dfs(node: Node, currentLevel: number) {
    if (!node) return;
    if (currentLevel > maxLevel) {
      maxLevel = currentLevel;
      ans = 0;
    }
    if (!node.left && !node.right && currentLevel === maxLevel) {
      ans += node.val;
    }
    dfs(node.left, currentLevel + 1);
    dfs(node.right, currentLevel + 1);
  }
  dfs(root, 1);
  return ans;
};
