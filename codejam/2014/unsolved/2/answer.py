# CodeJam 2014 - Qualification Round - Problem B Small
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)

tests = int(raw_input())

for t in range(1, tests + 1):
    p, time, spent = 2, 0, 0
    c, f, x = map(float, raw_input().split())
    while 1:
        time = x / float(p)
        farm = c / float(p)
        time_with_farm = (x / float(p + f)) + farm
        if time > time_with_farm:
            p += f
            spent += farm
        else:
            break
    spent += time
    print 'Case #%d: %.7f' % (t, spent,)
