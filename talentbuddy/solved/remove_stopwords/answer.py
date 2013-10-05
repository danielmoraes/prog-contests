def remove_stopwords(query, stopwords):
    h = {}
    for word in stopwords:
        h[word] = 1
    for q in query:
        if h.get(q) is None:
            print q

remove_stopwords(["the", "new", "store", "in", "SF"], ["the", "in"])
