from lexer import Token
from funcs import *


class Node(type):...


class Node:
    val: str
    chl: list[Node]
    typ: str

    def __init__(self, typ, val):
        self.typ, self.val, self.chl = typ, val, []
    
    def append(self, *vals):
        self.chl += list(vals)
    
    def __getitem__(self, index):
        return self.chl[index]


class Parser:
    file: str
    root: Node
    stack: list[int]
    src: str
    tokens: list[Token]

    def __init__(self):
        self.stack = []
    
    def input(self, file, source, tokens):
        self.file = file
        self.src = source
        self.root = Node('ROOT', self.src)
        self.tokens = tokens
        self.imports = []
    
    def parse(self):
        ind = 0
        while ind < len(self.tokens):
            tok = self.tokens[ind]

            if tok.type == 'IMP':
                if self.stack:
                    showError(self.file, self.src,
                              tok.pos, "unexpected keyword")
                ind += 1

                tok = self.tokens[ind]

                if tok.type != 'NAME':
                    showError(self.file, self.src,
                              tok.pos, "expected name")

                self.imports += [self.tokens[ind].val]

                ind += 1

                tok = self.tokens[ind]

                if tok.type != 'SCOL':
                    showError(self.file, self.src,
                              tok.pos, "expected semicolon")
            
            elif tok.type == 'FN':
                if self.stack:
                    showError(self.file, self.src,
                              tok.pos, "nested functions are not supported so far")
                
                ind += 1

                tok = self.tokens[ind]

                if tok.type != 'NAME':
                    showError(self.file, self.src,
                              tok.pos, "expected name")
                
                fname = tok.val

                ind += 1

                tok = self.tokens[ind]

                if tok.type != 'LN':
                    showError(self.file, self.src,
                              tok.pos, "expected \"(\"")
                
                ind += 1

                tok = self.tokens[ind]

                ind, args, types = self.parse_fargs(ind)

                ind += 1

                tok = self.tokens[ind]

                if tok.type != 'RN':
                    showError(self.file, self.src,
                              tok.pos, "expected \")\"")
            
            ind += 1