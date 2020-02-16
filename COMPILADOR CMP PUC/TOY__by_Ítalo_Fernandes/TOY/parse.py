from rply import ParserGenerator
class Parser():
    def __init__(self):
        self.pg = ParserGenerator(
            # A list of all token names accepted by the parser.
            ['NUM', 'IMPRIMA', 'ABRE_PAR', 'FECHA_PAR', 'PONTO_VIRGULA', 'SOMA', 'SUB', 'DIV' , 'MULT', 'POT', 'REST'],
			precedence=[ ('left', ['SUMA', 'SUB' , 'POT' , 'REST']), ('left', ['MUL', 'DIV']) ]
        )

    def parse(self):
        @self.pg.production('program : IMPRIMA ABRE_PAR expression FECHA_PAR PONTO_VIRGULA')
        def program(p):
            print(p[2])
		
        @self.pg.production('expression : ABRE_PAR expression FECHA_PAR') # adicionado
        def expression_par(p):#
            return p[1]#
       
        @self.pg.production('expression : expression REST expression')	#adicionado
        @self.pg.production('expression : expression POT expression')	#adicionado
        @self.pg.production('expression : expression SOMA expression')
        @self.pg.production('expression : expression SUB expression')
        @self.pg.production('expression : expression MULT expression')	#adicionado
        @self.pg.production('expression : expression DIV expression')	#adicionado
        def expression(p):
            left = p[0]
            right = p[2]
            operator = p[1]
            if operator.gettokentype() == 'SOMA':
                return (left + right)
            elif operator.gettokentype() == 'SUB':
                return (left - right)
            elif operator.gettokentype() == 'MULT':#
                return (left * right)#
            elif operator.gettokentype() == 'DIV':#
                return (left / right) #
            elif operator.gettokentype() == 'POT':#
                return (left ** right)#
            elif operator.gettokentype() == 'REST':#
                return (left % right)#
                
        @self.pg.production('expression : NUM')
        def number(p):
            return int(p[0].value)

        @self.pg.error
        def error_handle(token):
            raise ValueError(token)

    def get_parser(self):
        return self.pg.build()
