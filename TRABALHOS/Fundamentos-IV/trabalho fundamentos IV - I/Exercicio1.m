


%mediaAritmetica = 0;
%x = [4 5 6 8 9 10 20 56];
%n = length(x) 

n = input('Tamanho do vetor: ');
x = [0  ];
for i = 1: n
  x(i) = input('',i);
end 

sum = 0;   % soma normal
sum2 = 0;  % soma ao quadrado
 for i = 1 : n
  sum += x(i);    
  sum2 += x(i)*x(i);
end

% calc
mediaAritmetica = sum/n;
desvioPadrao = 1/(n-1)*(sum2 - (1/n)*(sum*sum));

% resultados
fprintf('Media Aritmetica:  %f\n',mediaAritmetica)
fprintf('Desvio Padrao:  %f\n',desvioPadrao)
  
  
  
  
  

  