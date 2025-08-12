// * 1305. All Elements in Two Binary Search Trees

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

type Node = TreeNode | null

function getValues(root: Node): number[] {
    const stack: Node[] = []
    const values: number[] = []
    stack.push(root)
    while (stack.length) {
        const node = stack.pop()
        values.push(node.val)
        if (node.left) stack.push(node.left)
        if (node.right) stack.push(node.right)
    }
    return values
}

function getAllElements(root1: Node, root2: Node): number[] {
    const result: number[] = []
    if (root1) result.push(...getValues(root1))
    if (root2) result.push(...getValues(root2))
    result.sort((a, b) => a - b)
    return result
};
