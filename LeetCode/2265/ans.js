/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var averageOfSubtree = function (root) {
  let ans = 0;

  // x = sum, y = quantity
  function dfs(root) {
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
