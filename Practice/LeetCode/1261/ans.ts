// * 1261. Find Elements in a Contaminated Binary Tree

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

type NodeT = TreeNode | null;

class FindElements {
  private recoveredValues: Set<number>;

  private bfs(root: NodeT): void {
    if (!root) return;

    root.val = 0;
    const pendingNodes: NodeT[] = [root];
    while (pendingNodes.length) {
      const currentNode = pendingNodes.pop();
      this.recoveredValues.add(currentNode.val);
      if (currentNode.left) {
        currentNode.left.val = currentNode.val * 2 + 1;
        pendingNodes.push(currentNode.left);
      }
      if (currentNode.right) {
        currentNode.right.val = currentNode.val * 2 + 2;
        pendingNodes.push(currentNode.right);
      }
    }
  }

  constructor(root: NodeT) {
    this.recoveredValues = new Set();
    this.bfs(root);
  }

  find(target: number): boolean {
    return this.recoveredValues.has(target);
  }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * var obj = new FindElements(root)
 * var param_1 = obj.find(target)
 */
