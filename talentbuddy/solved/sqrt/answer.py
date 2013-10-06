def compute_sqrt(n):
    sqrt, out, counter = 1, 1, 1
    while n > out + counter - 1:
        sqrt += 1
        counter += 2
        out += counter
    print int(sqrt)

compute_sqrt(17)
