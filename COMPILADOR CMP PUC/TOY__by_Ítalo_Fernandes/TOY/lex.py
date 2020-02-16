from rply import LexerGenerator

class Lexer():
	def __init__(self):
		self.lexer = LexerGenerator()
	
	def _add_tokens(self): 
		self.lexer.add('IMPRIMA', r'mostra_ai') #modificado heuhue
		self.lexer.add('ABRE_PAR', r'\(')
		self.lexer.add('FECHA_PAR', r'\)')
		self.lexer.add('PONTO_VIRGULA', r'\;')
		self.lexer.add('SOMA', r'\+')
		self.lexer.add('SUB', r'\-')
		self.lexer.add('NUM', r'\d+')
		self.lexer.add('MULT', r'\*')	#adicionado
		self.lexer.add('DIV', r'\/')	#adicionado
		self.lexer.add('POT',r'\^') 	#adicionado
		self.lexer.add('REST',r'\%') 	#adicionado
		self.lexer.ignore('\s+')
	
	def get_lexer(self):
		self._add_tokens()
		return self.lexer.build() 
