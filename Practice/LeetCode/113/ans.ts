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

function pathSum(root: Node, targetSum: number): number[][] {
  const answer: number[][] = [];
  const currentPath: number[] = [];
  const dfs = (root: Node, targetSum: number): void => {
    if (!root) return;
    if (root.left === null && root.right === null && targetSum - root.val === 0) {
      answer.push([...currentPath, root.val]);
      return;
    }
    currentPath.push(root.val);
    dfs(root.left, targetSum - root.val);
    dfs(root.right, targetSum - root.val);
    currentPath.pop();
  }
  dfs(root, targetSum);
  return answer;
};
