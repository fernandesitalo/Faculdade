% 	metodo de jacobi para sistemas nao lineares
%	Ajustar o criterio de parada, estou fazendo pelo numero de iteracoes


function [x] = MetodoJacobi(A,b,iteracoes,x) % numero de iteracoes , chute inicial

[L,C] = size(A); % L == C

% matriz de coeficientes deve ser quadrada
% matriz de Termos independetes deve ser compativel em dimensoes
 
TAM = L;

for i = 1 : iteracoes
	for j = 1 : TAM		
		temp(j,1) = Isolaequacao(A,b,j,x); 
	end
	x = temp;
end

end


% isola a variavel .: x[id] = ((termo idenpedente) - outras variveis) / A(id,id)
function ret = Isolaequacao(A,b,id,x)
	numerador = 0;
	denominador = 0;
	for i = 1 : 4
	%	printf(" == > %d %d\n",linha,i);
		if(i == id)
			denominador = A(id,i);
		else 
			numerador = numerador + A(id,i)*x(i,1);
		end
	end
	ret = (b(id,1) - numerador)/denominador;
end

