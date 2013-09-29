# Talent Buddy
# Missing Number
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)

def find_missing_number(v):
    n = len(v) + 1
    print n * (n + 1) / 2 - sum(v)

find_missing_number([5, 4, 1, 2])
