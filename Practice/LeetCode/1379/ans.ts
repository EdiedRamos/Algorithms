// * 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

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

function getTargetCopy(original: TreeNode | null, cloned: TreeNode | null, target: TreeNode | null): TreeNode | null {
  let ans :TreeNode | null = null;
  const dfs = (cloned: TreeNode | null, target: TreeNode | null) => {
    if (!cloned) return null;
    if (cloned.val === target.val) {
      ans = cloned;
      return;
    };
    dfs(cloned.left, target);
    dfs(cloned.right, target);
  }
  dfs(cloned, target);
  return ans;
};
