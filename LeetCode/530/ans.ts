// * 
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

function getMinimumDifference(root: Node): number {
  let ans = Infinity;
  const pending: Node[] = [root];
  const values: number[] = [];
  values.push(root.val);
  while (pending.length) {
    const current = pending.pop();
    const { left, right } = current;
    if (left) {
      values.push(left.val);
      pending.push(left);
    }
    if (right) {
      values.push(right.val);
      pending.push(right);
    }
  }
  values.sort((a, b) => a - b);
  for (let i = 0; i < values.length - 1; i++) {
    ans = Math.min(ans, values[i + 1] - values[i]);
  }
  return ans;
};
