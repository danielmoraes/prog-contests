# SPOJ 1226
# Favorite Dice (FAVDICE)
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)

t = int(raw_input())
for c in xrange(t):
    n = int(raw_input())
    m = 0.0
    for i in xrange(n):
        m += n / float(n - i)
    print '%.2f' % m
