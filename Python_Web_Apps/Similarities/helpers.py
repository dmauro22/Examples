from enum import Enum
from pprint import pprint


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""
    # The table will (word length + 1) x (word length + 1)
    # Initialize the matrix with the 'num' tuple
    num = [0, None]
    matrix = [[num for x in range(len(b)+1)] for y in range(len(a)+1)]

    # Top left corner should be blank:
    matrix[0][0] = [0, None]

    # Initialize the top row and far left column:
    for r in range(1, len(a)+1):
        matrix[r][0] = [r, Operation.DELETED]
    for c in range(1, len(b)+1):
        matrix[0][c] = [c, Operation.INSERTED]

    # Fill in all other values
    # Each current cell is determined by the cell above, to the left, and above-left
    for r in range(1, len(a)+1):
        for c in range(1, len(b)+1):
            if (((matrix[r-1][c-1][0]) <= (matrix[r-1][c][0])) and ((matrix[r-1][c-1][0]) <= (matrix[r][c-1][0]))):
                if a[r-1] == b[c-1]:
                    matrix[r][c] = [matrix[r-1][c-1][0], Operation.SUBSTITUTED]
                else:
                    matrix[r][c] = [matrix[r-1][c-1][0] + 1, Operation.SUBSTITUTED]

            else:
                if matrix[r-1][c][0] <= matrix[r][c-1][0]:
                    matrix[r][c] = [matrix[r-1][c][0] + 1, Operation.DELETED]
                else:
                    matrix[r][c] = [matrix[r][c-1][0] + 1, Operation.INSERTED]

    # pprint(matrix)
    return matrix
