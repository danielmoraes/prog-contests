def skyscrapers(heights):
    counter, water = 0, 0
    for i in xrange(1, len(heights)):
        s = counter + (heights[i] - heights[i - 1])
        counter = 0 if s >= 0 else s
        water += abs(counter)
    if counter < 0:
        h = heights[-1]
        for i in xrange(len(heights) - 1, 0, -1):
            if heights[i] > h:
                counter += heights[i] - h
                h = heights[i]
            if counter >= 0:
                break
            water -= abs(counter)
    print water

skyscrapers([9, 8, 7, 8, 9, 5, 6])
