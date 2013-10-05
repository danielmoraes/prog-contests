def token_stemming(tokens, suffixes):
    hash_s = {}
    for s in suffixes:
        hash_s[s] = 1
    for t in tokens:
        for i in xrange(len(t)):
            if not hash_s.get(t[i:]) is None:
                print t[:i]
                break
        else:
            print t

token_stemming(["friendly", "outgoing", "powerful", "in"],
               ["ing", "ly", "ul", "ful"])
