# SPOJ 42
# Adding Reversed Numbers (ADDREV)
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)

t = int(raw_input())
for c in xrange(t):
    n1, n2 = map(str, raw_input().split())
    print int(str(int(n1[::-1]) + int(n2[::-1]))[::-1])
