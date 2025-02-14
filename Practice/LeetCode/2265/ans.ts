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

function averageOfSubtree(root: Node): number {
  let ans = 0;

  // x = sum, y = quantity
  function dfs(root: Node): number[] {
    if (!root) return [0, 0];
    const [x1, y1] = dfs(root.left);
    const [x2, y2] = dfs(root.right);
    const sum = x1 + x2 + root.val;
    const quan = y1 + y2 + 1;
    const aver = Math.floor(sum / quan);
    if (root.val === aver) ans++;
    return [sum, quan];
  }

  dfs(root);

  return ans;
};
