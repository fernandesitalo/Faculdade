function [x] = MetodoGausSeidel(A,b,iteracoes,x) % numero de iteracoes , chute inicial

%%%%%%%%%%%%%%%%%%%% QUESTAO 3 %%%%%%%%%%%%%%%%%%%%%%%%%%
% A = [ 10 2 -3 5 ; 1 8 -1 1 ; 2 -1 -5 1 ; -1 2 3 20]; 	% matriz de coeficientes
% b = [ 48 ; 4 ; -11 ; 150 ];						    % matriz igualdade / termo idenpendente
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


[L,C] = size(A);
TAM = L;

for i = 1 : iteracoes
	for j = 1 : TAM
		x(j,1) = equacao(A,b,j,x); 
	end
end

end

% isola a variavel .: x[id] = ((termo idenpedente) - outras variveis) / A(id,id)
function ret = equacao(A,b,id,x)
	
	[L,C] = size(A); % L == C
	TAM = L;
	
	numerador = 0;
	denominador = 0;
	for i = 1 : L
	%	printf(" == > %d %d\n",linha,i);
		if(i == id)
			denominador = A(id,i);
		else 
			numerador = numerador + A(id,i)*x(i,1);
		end
	end
	ret = (b(id,1) - numerador)/denominador;
end


