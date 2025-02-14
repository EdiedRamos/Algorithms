<? // TODO: Remove this (<?) for leetcode
class Solution
{

  /**
   * @param Integer[] $arr
   * @param Integer $target
   * @return Integer
   */
  function threeSumMulti($arr, $target)
  {
    $fre = [];
    $ans = 0;
    $arr_length = count($arr);
    $MOD = 1e9 + 7;
    for ($i = 0; $i < $arr_length; $i++) {
      if (isset($fre[$target - $arr[$i]])) {
        $ans = ($ans + $fre[$target - $arr[$i]]) % $MOD;
      }
      for ($j = 0; $j < $i; $j++) {
        $fre[$arr[$i] + $arr[$j]] = ($fre[$arr[$i] + $arr[$j]] ?: 0) + 1;
      }
    }
    return $ans;
  }
}
