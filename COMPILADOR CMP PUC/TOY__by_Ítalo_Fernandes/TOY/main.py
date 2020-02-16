from lex import Lexer
from parse import Parser
from codegen import CodeGen

fname = "input.toy"
with open(fname) as f:
    text_input = f.read()

lexer = Lexer().get_lexer()
tokens = lexer.lex(text_input)

codegen = CodeGen()

module = codegen.module
builder = codegen.builder
printf = codegen.printf

#~ pg = Parser(module, builder, printf)
pg1 = Parser()
pg1.parse()
parser = pg1.get_parser()
parser.parse(tokens)

codegen.create_ir()
#~ codegen.save_ir("output.ll")
