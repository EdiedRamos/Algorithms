<? // TODO: Delete this "<?" for leetcode

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($val = 0, $left = null, $right = null) {
 *         $this->val = $val;
 *         $this->left = $left;
 *         $this->right = $right;
 *     }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root
     * @return TreeNode
     */
    function dfs($root, $sum) {
      if (!isset($root)) return $sum;
      $root->val += $this->dfs($root->right, $sum);
      return $this->dfs($root->left, $root->val);
    }

    function bstToGst($root) {
      $this->dfs($root, 0);
      return $root;
    }
}
