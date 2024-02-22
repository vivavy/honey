from funcs import *
import lexer
import parse
import sys
import os


os.system("cls")

infile = sys.argv[-1]

with open(infile, "rt") as f:
    src = f.read()

rules = (
    (r"\/\*[^(\*\/)\*\/]", 'COMM'),
    (r'".*"', 'STR'),
    (r"\d+", 'NUM'),
    (r"import", 'IMP'),
    (r"fn", 'FN'),
    (r"\b[A-Za-z_]\w*\b", 'NAME'),
    (r"\(", 'LN'),
    (r"\)", 'RN'),
    (r"\<-", 'RAR'),
    (r"-\>", 'LAR'),
    (r"\<", 'LA'),
    (r"\>", 'RA'),
    (r";", 'SCOL'),
    (r":", 'COLON'),
    (r",", 'COMMA'),
    (r"\{", 'LC'),
    (r"\}", 'RC'),
)

lx = lexer.Lexer(rules)

lx.input(src)

try:
    tokens = list(lx.tokens())

    print("Tokens:")
    
    for token in tokens:
        print("\t", token.type, "\t", token.val, "\t", "\t".join(tuple(str(i) for i in getSymPos(src, token.pos))))

except lexer.LexerError as e:
    symno = int(str(e).strip())
    col, row = getSymPos(src, symno)
    line = src.split("\n")[row]
    sym = src[symno]

    print("error in file", repr(os.path.abspath(infile)) + ", line", row)
    print("\t", line)
    print((("~" * (col - 1)) if col > 0 else "") + "^")
    print("unexpected symbol:", repr(sym))
