// * 993. Cousins in Binary Tree

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
interface NodeInfo {
  parent: number;
  depth: number;
};

function isCousins(root: Node, x: number, y: number): boolean {
  const currentNodes: Node[] = [];
  const info: Record<number, NodeInfo> = {};
  currentNodes.push(root);
  info[root.val] = {
    parent: -1,
    depth: 0
  };
  while (currentNodes.length) {
    const currentNode = currentNodes.pop();
    const currentInfo = info[currentNode.val];
    const { left, right } = currentNode;
    if (left) {
      info[left.val] = {
        parent: currentNode.val,
        depth: currentInfo.depth + 1
      };
      currentNodes.push(left);
    }
    if (right) {
      info[right.val] = {
        parent: currentNode.val,
        depth: currentInfo.depth + 1
      };
      currentNodes.push(right);
    }
  }
  const nodeX: NodeInfo = info[x];
  const nodeY: NodeInfo = info[y];
  return nodeX.parent !== nodeY.parent && nodeX.depth === nodeY.depth;
};
