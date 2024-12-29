
<?
  class RLEIterator
  {
    /**
     * @param Integer[] $encoding
     */
    function __construct($encoding)
    {
      $this->encoding = $encoding;
    }

    private function removeCurrent()
    {
      if ($this->encoding[0] === 0) {
        array_shift($this->encoding);
        array_shift($this->encoding);
      }
    }

    /**
     * @param Integer $n
     * @return Integer
     */
    function next($n)
    {
      while ($n > 0 && count($this->encoding) > 0) {
        if ($n <= $this->encoding[0]) {
          $last = $this->encoding[1];
          $this->encoding[0] -= $n;
          $this->removeCurrent();
          return $last;
        } else {
          $n -= $this->encoding[0];
          $this->encoding[0] = 0;
          $this->removeCurrent();
        }
      }
      return -1;
    }
  }

  /**
   * Your RLEIterator object will be instantiated and called as such:
   * $obj = RLEIterator($encoding);
   * $ret_1 = $obj->next($n);
   */
