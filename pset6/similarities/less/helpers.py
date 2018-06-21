from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    a1 = set(a.split('\n'))
    b1 = set(b.split('\n'))
    ans = []

    for line in a1:
        if line in b1:
            ans.append(line)

    return ans


def sentences(a, b):
    """Return sentences in both a and b"""
    a1 = set(sent_tokenize(a))
    b1 = set(sent_tokenize(b))
    ans = []

    for line in a1:
        if line in b1:
            ans.append(line)

    return ans


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    a1 = []
    for i in range(0, len(a) - n + 1):
        a1.append(a[i:i + n])
    a1 = set(a1)

    b1 = []
    for i in range(0, len(b) - n + 1):
        b1.append(b[i:i + n])
    b1 = set(b1)

    ans = []

    print(a1)
    print(b1)

    for line in a1:
        if line in b1:
            ans.append(line)

    return ans