from enum import Enum


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""
    score = [[(0, Operation.DELETED) for x in range(len(b) + 1)] for y in range(len(a) + 1)]

    score[0][0] = (0, Operation.DELETED)
    for i in range(1, len(a) + 1):
        score[i][0] = (score[i - 1][0][0] + 1, Operation.DELETED)

    score[0][0] = (0, Operation.DELETED)
    for i in range(1, len(b) + 1):
        score[0][i] = (score[0][i - 1][0] + 1, Operation.DELETED)

    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            match = not(a[i - 1] == b[j - 1])
            match, insert, delete = score[i - 1][j - 1][0] + match, score[i - 1][j][0] + 1, score[i][j - 1][0] + 1
            if(min(match, delete, insert) == match):
                score[i][j] = (match, Operation.SUBSTITUTED)
            if(min(match, delete, insert) == delete):
                score[i][j] = (delete, Operation.DELETED)
            if(min(match, delete, insert) == insert):
                score[i][j] = (insert, Operation.INSERTED)

    for i in range(len(a) + 1):
        for j in range(len(b) + 1):
            print(score[i][j][0], end=' ')
        print()

    # print(score[len(a)][len(b)][0])
    return score
