function [Yret] = RungeKutta4(l,r,h,valorInicial)
H = (r-l)/h;
Yanterior = valorInicial;
Xanterior = l;
Yatual = 0;
for i = 1 : H
  k1 = yderivada(Xanterior,Yanterior);
  k2 = yderivada(Xanterior+h/2.,Yanterior+k1*h/2.);
  k3 = yderivada(Xanterior+h/2.,Yanterior+k2*h/2.);
  k4 = yderivada(Xanterior+h,Yanterior + h*k3);
  Yatual = Yanterior + h/6*(k1 + 2*k2 + 2*k3 + k4);
  Yanterior = Yatual;
  Xanterior = Xanterior + h;
endfor
Yret = Yatual;
endfunction

function [yderivada] = yderivada(x,y)
  %yderivada = tan(y)+1; 
  %yderivada = 2*x*y ;
  yderivada = 1+x*x;
endfunction 