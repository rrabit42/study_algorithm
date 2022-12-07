import sys

N = int(input())

book = []
for _ in range(N):
    name, korea, english, math = sys.stdin.readline().split(' ')
    korea = int(korea)
    english = int(english)
    math = int(math)
    # print(f"{korea} {english} {math} {name}")
    book.append((korea, english, math, name))

book.sort(key=lambda x: (-x[0], x[1], -x[2], x[3]))

for _, _, _, name in book:
    print(name)
