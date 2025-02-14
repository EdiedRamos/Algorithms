class Solution {

    /**
     * @param String $current
     * @param String $correct
     * @return Integer
     */
    function convertTime($current, $correct) {
        $p1 = preg_split("/:/", $current);
        $p2 = preg_split("/:/", $correct);
        $differ = ($p2[0] * 60 + $p2[1]) - ($p1[0] * 60 + $p1[1]);
        $options = [60, 15, 5, 1];
        $times = 0;
        for ($i = 0; $i < count($options); $i++) {
          while ($differ >= $options[$i]) {
            $differ -= $options[$i];
            $times++;
          }
        }
        return $times;
    }
}
