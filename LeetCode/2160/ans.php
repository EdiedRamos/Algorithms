class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function minimumSum($num) {
      $numbers = str_split($num);
      sort($numbers);
      // var_dump($numbers);
      return ($numbers[0] * 10 + $numbers[2]) + ($numbers[1] * 10 + $numbers[3]);
    }
}
