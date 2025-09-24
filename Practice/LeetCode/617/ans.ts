// * 617. Merge Two Binary Trees

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

function createNode(): TreeNode {
  return {
    val: 0,
    left: null,
    right: null,
  }
}

function mergeTrees(
  root1: TreeNode | null,
  root2: TreeNode | null
): TreeNode | null {
  if (!root1) return root2
  if (!root2) return root1

  let head: TreeNode | null = createNode()

  const subDfs = (baseRoot: TreeNode | null, cloneRoot: TreeNode | null) => {
    if (!baseRoot) return
    if (!cloneRoot) cloneRoot = createNode()

    cloneRoot.val = baseRoot.val

    if (baseRoot.left) {
      cloneRoot.left = createNode()
      subDfs(baseRoot.left, cloneRoot.left)
    }
    if (baseRoot.right) {
      cloneRoot.right = createNode()
      subDfs(baseRoot.right, cloneRoot.right)
    }
  }

  const dfs = (
    root1: TreeNode | null,
    root2: TreeNode | null,
    root3: TreeNode | null
  ): void => {
    if (!root1 || !root2) return

    if (!root3) root3 = createNode()
    root3.val = root1.val + root2.val

    if (root1.left || root2.left) root3.left = createNode()
    if (root1.right || root2.right) root3.right = createNode()

    if (root1.left && root2.left) dfs(root1.left, root2.left, root3.left)
    if (root1.right && root2.right) dfs(root1.right, root2.right, root3.right)

    if (root1.left && !root2.left) subDfs(root1.left, root3.left)
    if (root1.right && !root2.right) subDfs(root1.right, root3.right)

    if (root2.left && !root1.left) subDfs(root2.left, root3.left)
    if (root2.right && !root1.right) subDfs(root2.right, root3.right)
  }

  dfs(root1, root2, head)

  return head
}
