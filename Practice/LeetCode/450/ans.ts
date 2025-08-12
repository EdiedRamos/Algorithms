// * 450. Delete Node in a BST

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
interface NodeInfo {
  parent: Node
  current: Node
}

function getLowestNode(root: Node, start: Node): NodeInfo {
  let lowest: Node = start
  let parent: Node = root
  while (lowest.left) {
    parent = lowest
    lowest = lowest.left
  }
  return {
    parent,
    current: lowest,
  }
}

function deleteNode(root: Node, key: number): Node {
  if (!root) return root

  if (!root.left && !root.right) {
    return root.val === key ? null : root
  }

  const nodes: NodeInfo[] = [{ parent: null, current: root }]
  while (nodes.length) {
    let { parent, current } = nodes.pop()
    if (current.val === key) {
      if (!current.left && !current.right) {
        if (parent.left?.val === key) parent.left = null
        else parent.right = null
      } else if (
        (current.left &&
          !current.right &&
          !current.left.left &&
          !current.left.right) ||
        (current.right &&
          !current.left &&
          !current.right.right &&
          !current.right.left)
      ) {
        current.val = current.left ? current.left.val : current.right.val
        current.left = null
        current.right = null
      } else {
        if (!current.right) {
          if (!parent) root = current.left
          else if (parent?.left?.val === current.val) parent.left = current.left
          else parent.right = current.left
          break
        }

        const target = getLowestNode(current, current.right)
        current.val = target.current.val
        if (!target.current.left && !target.current.right) {
          if (target.parent?.left?.val === target.current.val)
            target.parent.left = null
          else if (target.parent) target.parent.right = null
        } else {
          if (target.parent.left.val === target.current.val) {
            target.parent.left = target.current.right
          } else {
            target.parent.right = target.current.right
          }
        }
      }
      break
    }

    if (current.left) nodes.push({ parent: current, current: current.left })
    if (current.right) nodes.push({ parent: current, current: current.right })
  }
  return root
}
