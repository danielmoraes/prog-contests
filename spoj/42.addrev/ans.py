# SPOJ 42
# Adding Reversed Numbers (ADDREV)
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)


def revert(n):
    n = list(n)
    s = len(n)
    for i in xrange(s / 2):
        inv = s - i - 1
        n[i], n[inv] = n[inv], n[i]
    return int(''.join(n))

t = int(raw_input())
for c in xrange(t):
    n1, n2 = map(str, raw_input().split())
    print '%d' % revert(str(revert(n1) + revert(n2)))
