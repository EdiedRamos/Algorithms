// 2196. Create Binary Tree From Descriptions

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

function createBinaryTree(descriptions: number[][]): TreeNode | null {
  const treeReference = new Map<number, TreeNode>();
  const isChild = new Set<number>();

  for (const [parentVal, childVal, isLeft] of descriptions) {
    if (!treeReference.has(parentVal)) {
      treeReference.set(parentVal, new TreeNode(parentVal));
    }

    if (!treeReference.has(childVal)) {
      treeReference.set(childVal, new TreeNode(childVal));
    }

    const parentNode = treeReference.get(parentVal)!;
    const childNode = treeReference.get(childVal)!;

    if (isLeft === 1) {
      parentNode.left = childNode;
    } else {
      parentNode.right = childNode;
    }

    isChild.add(childVal);
  }

  for (const [parentVal] of descriptions) {
    if (!isChild.has(parentVal)) {
      return treeReference.get(parentVal) ?? null;
    }
  }

  return null;
}
