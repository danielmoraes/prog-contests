def tuple_sum(a, s):
    hash = {}
    matrix = [[0 for j in xrange(len(a))] for i in xrange(len(a))]

    for i in xrange(len(a)):
        for j in xrange(len(a)):
            if i == j:
                continue
            sum = a[i] + a[j]
            matrix[i][j] = sum
            if hash.get(sum) is None:
                hash[sum] = []
            hash[sum].append([i, j])

    for i in xrange(len(a)):
        for j in xrange(len(a)):
            if i == j:
                continue
            sum = matrix[i][j]
            diff = s - sum
            if diff >= 0:
                if hash.get(diff) is not None:
                    for el in hash[diff]:
                        if el[0] not in [i, j] and el[1] not in [i, j]:
                            print '%d %d %d %d' % (i, j, el[0], el[1])
                            return

tuple_sum([3, 2, 1, 4, 5, 7, 6, 9, 7, 8], 30)
