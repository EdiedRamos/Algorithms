<? // TODO: Remove this "<?" for leetcode
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function thirdMax($nums) {
      $diff = array_unique($nums);
      rsort($diff);
      return count($diff) > 2 ? $diff[2] : $diff[0];
    }
}
