import sys

input = sys.stdin.readline

match = {
  ")": "(",
  "]": "["
}

while True:
  line = input().rstrip()
  if line == ".":
    break

  stack = []
  for word in line: # word라기엔 letter 혹은 ch가 알맞은 표현일듯
    # if word == "(" or word == "[":
    if word in "([":
      stack.append(word)
    elif word == ")" or word == "]":
      if stack and stack.pop() == match[word]:
        continue
      else:
        stack.append(word)
        break

  if not stack:
    print("yes")
  else:
    print("no")
