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
        ...