function [L] = cholesky(A)

[l,c] = size(A);
tam = l;

% inicializa matriz L
for j = 1 : tam
  for i = 1 : tam
    L(i,j) = 0;
  end
end


% realiza calculos
for i = 1 : tam
  for j = 1 : i
    if i == j     % CASO 1 -> i == j
      temp = 0;
      for k = 1 : (i-1)
        temp = temp + L(i,k)*L(i,k); % formula
      end
      L(i,i) = sqrt(A(i,i) - temp);
    else          % CASO 2 -> i != J
      temp = 0;
      for k = 1 : (j-1)
        temp = temp + L(i,k)*L(j,k);
      end
      L(i,j) = (A(i,j)-temp)/L(j,j); % formula
    end
  end
end
end
