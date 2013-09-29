def tweets_per_second(tps, k):
    l = len(tps)
    cm = tps[0]
    ck = k
    for i in xrange(l):
        if ck > 0:
            if cm <= tps[i]:
                cm = tps[i]
                ck = k
        else:
            tpsk = tps[i - k + 1: i + 1]
            cm = 0
            for j in xrange(k):
                if tpsk[j] > cm:
                    cm = tpsk[j]
                    ck = j + 1
        print cm
        ck -= 1

tweets_per_second([6, 9, 4, 7, 4, 1], 3)
