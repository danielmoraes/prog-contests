# SPOJ 11110
# Favorite Dice (ELIS)
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)

n, s1 = int(raw_input()), map(int, raw_input().split())
s2 = list(set(s1))
s2.sort()
m = [[0 for i in xrange(len(s2) + 1)] for j in xrange(len(s1) + 1)]
for i in xrange(1, len(m)):
    for j in xrange(1, len(m[0])):
        if s1[i - 1] == s2[j - 1]:
            m[i][j] = m[i - 1][j - 1] + 1
        else:
            m[i][j] = max(m[i][j - 1], m[i - 1][j])
print m[len(m) - 1][len(m[0]) - 1]
