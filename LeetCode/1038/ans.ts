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

type NodeType = TreeNode | null;

function dfs(root: NodeType, sum: number): number {
  if (!root) return sum;
  const rightSum = dfs(root.right, sum);
  root.val += rightSum;
  return dfs(root.left, root.val);
}

function bstToGst(root: NodeType): NodeType {
  dfs(root, 0);
  return root;
};
