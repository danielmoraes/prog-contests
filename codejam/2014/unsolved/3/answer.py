# CodeJam 2014 - Qualification Round - Problem C
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)

tests = int(raw_input())

for c in range(1, tests + 1):
    r, c, m = map(int, raw_input())
    grid = [[0 for i in xrange(c)] for j in xrange(r)]
    row_markers, col_markers = [0, 0], [0, 0]
    while m > 0:
        if r < c:
            if m > r:
                best_c = col_markers.index(min(col_markers))
                col_markers[best_c] += 1
                for i in xrange(r):
                    if best_c == 0:
                        grid[i][col_markers[best_c]] = 1
                    else:


