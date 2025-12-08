# * Find the unique toy

def find_unique_toy(toy: str) -> str:
  characters_frecuency = {}
  for character in toy:
    character = character.lower()
    if character in characters_frecuency:
        characters_frecuency[character] += 1
    else:
        characters_frecuency[character] = 1
  for character in toy:
    if characters_frecuency[character.lower()] == 1:
        return character
  return ''
