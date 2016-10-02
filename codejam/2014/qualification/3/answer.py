# CodeJam 2014 - Qualification Round - Problem C
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)

tests = int(raw_input())

for c in range(1, tests + 1):
    r, c, m = map(int, raw_input().split())
    grid = [[0 for i in xrange(c)] for j in xrange(r)]
    row_markers, col_markers = [0, 0], [0, 0]
    while m > 0:
        if r < c:
            if m > r:
                best_c = col_markers.index(min(col_markers))
                for i in xrange(r):
                    if best_c == 0:
                        grid[i][col_markers[best_c]] = 1
                    else:
                        grid[i][col_markers[-1 - best_c]] = 1
                col_markers[best_c] += 1
                m -= r
            else:
                m = 0
        else:
            if m > c:
                best_r = row_markers.index(min(row_markers))
                for i in xrange(c):
                    if best_r == 0:
                        grid[row_markers[best_r]][i] = 1
                    else:
                        grid[row_markers[-1 - best_r]][i] = 1
                row_markers[best_r] += 1
                m -= c
            else:
                m = 0
    for i in xrange(r):
        print ' '.join(map(str, grid[i]))
    print
