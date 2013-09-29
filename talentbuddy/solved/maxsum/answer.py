def find_max_sum(v):
    s1, s2 = 0, 0
    for i in xrange(len(v)):
        s = max(s1, s2 + v[i])
        s2, s1 = s1, s
    print s1

find_max_sum([2, 5, 6, 5, 3])
