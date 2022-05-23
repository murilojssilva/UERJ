function transf(p0, p1)

  pkg load image;
  
  % x0 = input('Insira o 1 ponto que delimita a imagem original: ');
      
  % Matriz dos coeficientes (sistema de equações)  
  A = [x0 y0 1 0 0 0 (−1)*x0*x0L (−1)*y0*x0L;
       0 0 0 x0 y0 1 (−1)*x0*y0L (−1)*y0*y0L;
       x1 y1 1 0 0 0 (−1)*x1*x1L (−1)*y1*x1L;
       0 0 0 x1 y1 1 (−1)*x1*y1L (−1)*y1*y1L;
       x2 y2 1 0 0 0 (−1)*x2*x2L (−1)*y2*x2L;
       0 0 0 x2 y2 1 (−1)*x2*y2L (−1)*y2*y2L;
       x3 y3 1 0 0 0 (-1)*x3*x3L (-1)*y3*x3L;
       0 0 0 x3 y3 1 (−1)*x3*y3L (−1)*y3*y3L];
  
  % Matriz dos coeficientes (transformação projetiva)  
  L = [x0L; y0L; x1L; y1L; x2L; y2L; x3L; y3L];

  % Matriz de observações  
  % L = A*x;
  % x = (At . A)^-1 . At . L
  x = inv((A.')*A)*((A.')*L);
  % Se A.' não der certo, testar A'

  % x resultará em uma matriz 8(colunas) x 1(linha) 
  % Mas queremos obter a matriz de transformação 3 x 3 a partir desses elementos de x
  % Para isso, deve-se preencher o último elemento da matriz com "1"
  
  A = x(1, 1); % linha 1, coluna 1
  B = x(1, 2); % linha 1, coluna 2  
  C = x(1, 3); % linha 1, coluna 3  
  D = x(1, 4); % linha 1, coluna 4
  E = x(1, 5); % linha 1, coluna 5
  F = x(1, 6); % linha 1, coluna 6
  G = x(1, 7); % linha 1, coluna 7
  H = x(1, 8); % linha 1, coluna 8  
  
  % Matriz de Transformação
  T = [A B C; D E F; G H 1];
  
  % Matrizes Cn que serão multiplicadas por T para normalizá-la
  
  C0 = [x0; y0; 1]; % [xk yk 1], sendo k = 0
  C1 = [x1; y1; 1]; % [xk+1 yk+1 1] 
  C2 = [x2; y2; 1]; % [xk+2 yk+2 1]  
  C3 = [x3; y3; 1]; % [xk+n yk+n 1], sendo n = 3 
  % Tk = [xk''; yk''; zk'']
  % Matriz 3x3 * Matriz 3x1 = Matriz 3x1
  T0 = T*C0; % Coluna 1 da matriz
  T1 = T*C1;
  T2 = T*C2;
  T3 = T*C3;.

  z0 = T0(3, 1); % linha 3, coluna 1 
  z1 = T1(3, 1);
  z2 = T2(3, 1);
  z3 = T3(3, 1);
  
  T0 = T0/z0;
  T1 = T0/z1;
  T2 = T0/z2;
  T3 = T0/z3;
  
  % Unimos as 4 matrizes 3x1, formando a matriz de transformação 3x4 normalizada
  Tn = cat(4, T0, T1, T2, T3);
  % A normalização das coordenadas serve para que vire um plano afim, para que eu possa usar as propriedades e transformações afins

 
  figure('Name','Figura Original','NumberTitle','off');
  imshow(img)
  figure('Name','Figura Transformada','NumberTitle','off');
  imshow(new_img)
  
endfunction