def has_four_lights(board: list[list[str]]) -> bool:
  rows = len(board)
  cols = len(board[0])
  for r in range(rows):
    for c in range(cols):
      value = board[r][c]
      if value == '.':
        continue
      if c + 3 < cols and value == board[r][c+1] and value == board[r][c+2] and value == board[r][c+3]:
        return True
      if r + 3 < rows and value == board[r+1][c] and value == board[r+2][c] and value == board[r+3][c]:
        return True
  return False
