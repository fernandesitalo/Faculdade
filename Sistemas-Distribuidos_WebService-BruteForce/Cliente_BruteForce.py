
import json
import requests
import hashlib
import ast


if __name__ == '__main__':
	while True:
		msg = {'nome' : 'italo'}
		response = requests.get('http://127.0.0.1:5000/bruteforce/task',json = msg )
		block = eval(response.content)
		if len(block) == 0:
			continue
			
		hash_key = block['hash_key']
		passwords = block['passwords']
		
		for password in passwords:
			hsh_calc = hashlib.md5(password).hexdigest()
			print(" -----> ", password)
			if hash_key == hsh_calc:
				# mandar um post avisando que recebeu
				msg = {'found' : True,'password' : password}
				requests.post('http://127.0.0.1:5000/bruteforce/response', json = msg, headers = {'Content-Type' : 'application/json'})
				exit(0)
				
		msg = {'found' : False, 'password' : ''}
		requests.post('http://127.0.0.1:5000/bruteforce/response', json = msg)




