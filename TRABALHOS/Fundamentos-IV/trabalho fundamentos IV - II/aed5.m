

%	X -> matriz de "pontos"(primeira linha é um ponto, segunda linha outro...)
% 
%	Y -> matriz com a imagem dos "pontos"
%	um ponto qualquer ->  ( X1,X2 ,X3, ... , Y)
%
%	A -> matriz de coeficientes
%	x -> solucao
%
%  	A*x = b .: x = b*inv(A)


clear

X = [	25.5 1.74 5.30 	;
		31.2 6.32 5.42 	;
		25.9 6.22 8.41 	;
		38.4 10.52 4.63	;
		18.4 1.19 11.60 ;
		26.7 1.22 5.85 	;
		26.4 4.10 6.62	; 
		25.9 6.32 8.72 	;
		32.0 4.08 4.42 	;
		25.2 4.15 7.60 	;
		39.7 10.15 4.83 ;
		35.7 1.72 3.12 	;
		26.5 1.70 5.30 		];

Y = [10.80 9.40 7.20 8.50 9.40 9.90 8.00 9.10 8.70 9.20 9.40 7.60 8.20];



%N pontos
%cada ponto com C+1 coordenadas
[N,C] = size(X);

% pre-processamento dos dados
% SUM(i,j)  ====> somatorio das variaveis i e j
for j = 1 : C
  for i = 1 : j
    SUM(i,j) = 0;
    SUM(j,i) = 0;
    for k = 1 : N
      SUM(i,j) = SUM(i,j) + X(k,j)*X(k,i);
    endfor
    SUM(j,i) = SUM(i,j);
  endfor
endfor

% somatorio somente da variavel 'X'
sumx(1) = 1;
for j = 1 : C
  sumx(j+1) = 0;
  for i = 1 : N
    sumx(j+1) = sumx(j+1) + X(i,j);
   endfor
endfor
 
 
% somatorio da coordenada 'Y'
sumy = 0;
for i = 1 : N
	sumy = sumy + Y(i);
endfor


%montagem da matriz de coeficientes [A]
T = C+1;  % quantidade de linhas
for i = 1 : T %linha
	for j = 1 : T	%coluna
		if (i == j && i == 1)
			A(i,j) = N;
		else if (i == 1 || j == 1)
      A(i,j) = sumx( i+j -1);
    else
			A(i,j) = SUM(i-1,j-1);
		endif
    endif
	endfor
endfor
	
% montagem matriz [b]
b(1) =sumy;
for i = 2 : T
  b(i) = 0;
  for k = 1 : N
    b(i) = b(i) + X(k,i-1)*Y(k);
  endfor
endfor

x = b * inv(A);
printf("Matrizes pre computadas:\n");
A
b
printf("solucao do sistema em x, sendo x = b * inv(A): ")
x

% MODELO RLM ->  y =   12.42   - 0.10*(x1)    0.06*(x2)   -0.16*(x3)
