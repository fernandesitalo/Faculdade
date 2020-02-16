from flask import Flask
from flask import jsonify
from flask import request
import requests
import json

app = Flask(__name__)

Protected = True
BLOCK_SIZE = 5000
archive = open("rockyou.txt")#, encoding = "latin-1", mode = "r") # verificar isso aqui em casa


'''
    fazer verificacao se a requisicao feita veio de um cliente conhecido. OK
'''
clientes = ['cliente1','cliente2']

#   abrir arquivo e ler BLOCK_SIZE linhas, enviar para cliente.
def getNextBlock():
    block = {'passwords': [], 'hash_key' : '947d9a3043a5dda749adaf9baeab08fe'}
    password = archive.readline()
    if password:
        block['passwords'].append(password)
        for i in range(BLOCK_SIZE-1):
            password = archive.readline()
            if password:
                block['passwords'].append(password)
            else:
                break
    return block
    

#   retorna wordList com BLOCK_SIZE passwords
@app.route('/bruteforce/task',methods=['GET'])
def getTask():
    dat = {
        'nome' : request.json['nome']
    }
    if dat['nome'] in clientes:
        wordList = getNextBlock()
        if len(wordList['passwords']):
            return wordList
        else:
            print("A WORDLIST ACABOU!")
            exit(0)
    else:
        print("\n\nRequisicao NEGADA!!\n\n")
    return {} #	retorna um dict vazio caso n seja um de seus clientes

#   obtem a resposta do cliente
@app.route('/bruteforce/response',methods=['POST'])
def ResponseCliente():
    dat = {
    'found': request.json['found'],
    'password': request.json['password']
    }
    print(type(dat))
    if dat['found'] == True:
        print("\n\n\n")
        print("CONSEGUIMOS QUEBRAR A SENHA!")
        print("senha : " + dat['password'])
        print("\n\n\n")
        exit(0)
    else:
        print("Estamos tentanto")
    return jsonify(dat)
    
if __name__ == '__main__':
 app.run()
