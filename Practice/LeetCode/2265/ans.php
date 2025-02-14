<?

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
     * @return Integer
     */

    private $ans = 0;

    function averageOfSubtree($root) {
        $this->dfs($root);
        return $this->ans;
    }

    private function dfs($root) {
      if (!isset($root)) return [0, 0];

      list($x1, $y1) = $this->dfs($root->left);
      list($x2, $y2) = $this->dfs($root->right);

      $sum = $x1 + $x2 + $root->val;
      $quan = $y1 + $y2 + 1;

      $aver = intdiv($sum, $quan);

      if ($root->val === $aver) {
        $this->ans++;
      }

      return [$sum, $quan];
    }
}
