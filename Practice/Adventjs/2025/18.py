# Lights in line with diagonals

def has_four_in_a_row(board: list[list[str]]) -> bool:
  rows, cols = len(board), len(board[0])
  directions = [
    (0, 1),
    (1, 0),
    (1, 1),
    (-1, 1)
  ]

  for r in range(rows):
    for c in range(cols):
        val = board[r][c]
        if val == '.':
          continue

    for dr, dc in directions:
      if all(
        0 <= r + dr * k < rows and
        0 <= c + dc * k < cols and
        board[r + dr * k][c + dc * k] == val
        for k in range(4)
      ):
        return True

    return False
