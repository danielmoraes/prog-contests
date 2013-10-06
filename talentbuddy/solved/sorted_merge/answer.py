def merge_arrays(a, b):
    i, j, l = 0, 0, []
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            print(a[i]),
            i += 1
        else:
            print(b[j]),
            j += 1
    for k in xrange(i, len(a)):
        print(a[i]),
    for k in xrange(j, len(b)):
        print(b[k]),

merge_arrays([2, 3, 7, 8, 8], [7, 8, 13])
