# CodeJam 2014 - Qualification Round - Problem A
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)


def load_grid():
    grid = []
    for i in range(4):
        grid.append(map(int, raw_input().split()))
    return grid


for c in range(1, int(raw_input()) + 1):
    found, bad = 0, 0
    valids = [0 for i in range(16)]
    for i in range(2):
        answer = int(raw_input())
        grid = load_grid()
        for j in range(4):
            v = grid[answer - 1][j]
            valids[v - 1] += 1
            if valids[v - 1] == 2:
                if found != 0:
                    bad = 1
                    break
                found = v
        if bad:
            break

    if found:
        if bad:
            print 'Case #%d: Bad magician!' % c
        else:
            print 'Case #%d: %d' % (c, found,)
    else:
        print 'Case #%d: Volunteer cheated!' % c
