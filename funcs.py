import os
import sys


def listSplit(lst: list, key):
    rv = [[]]

    for i in lst:
        if key(i):
            rv += [[]]
            continue
        rv[-1] += [i]
    
    return tuple(rv)


def getSymPos(text, symno):
    col, row = 0, 0

    for n in range(symno):
        sym = text[n]
        col += 1
        if sym == "\n":
            col = 0
            row += 1
    
    return col, row


def showError(file, text, symno, error):
    col, row = getSymPos(text, symno)
    line = text.split("\n")[row]
    print("error in file", repr(os.path.abspath(file)) + ", line", row)
    print("\t", line)
    print("~" * (col + 3) + "^")
    print(error)
    sys.exit(1)
