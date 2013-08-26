# SPOJ 1226
# Favorite Dice (FAVDICE)
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)

t = int(raw_input())
for c in xrange(t):
    n = int(raw_input())
    print '%.2f' % sum([n / float(n - i) for i in xrange(n)])
