<? // delete for lc
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {

    /**
     * @param ListNode $head
     * @return ListNode
     */
    function swapPairs($head) {
      $aux = $head;
      while ($aux !== null) {
        if ($aux->next !== null) {
          $tmp = $aux->val;
          $aux->val = $aux->next->val;
          $aux->next->val = $tmp;
          $aux = $aux->next;
        }
        $aux = $aux->next;
      }
      return $head;
    }
}
