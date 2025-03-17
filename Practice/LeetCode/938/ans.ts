// * 938. Range Sum of BST

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

function rangeSumBST(root: TreeNode | null, low: number, high: number): number {
  let ans = 0;
  const dfs = (root: TreeNode | null, low: number, high: number): void => {
    if (!root) return;
    if (root.val >= low && root.val <= high) ans += root.val;
    dfs(root.left, low, high);
    dfs(root.right, low, high);
  }
  dfs(root, low, high);
  return ans;
};
