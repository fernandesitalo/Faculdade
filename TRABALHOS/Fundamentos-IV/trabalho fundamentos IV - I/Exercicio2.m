

%m = input('numero de linhas matriz 1: ')
%n = input('numero de colunas matriz 1: ')

% como "declarar" uma matriz de tamanho mxn ?
mat = [1 2 3; 4 5 6; 7 8 9];

m = 3;
n = 3;

x = [0 0 0]; % maiores elementos de cada linha sao armazenados nesse vetor

for i = 1 : m
  maxelement = -inf;
  for j = 1 : n
    maxelement = max(maxelement,mat(i,j));
  end
  x(i) = maxelement;
end

for i = 1 : m
  fprintf("Maior elemento da linha %d: %d\n",i,x(i))
end
fprintf("\n\n")