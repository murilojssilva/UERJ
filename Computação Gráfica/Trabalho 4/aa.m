pkg load image;  

                      %sup_o = [1 c-1 c-1 1;
                      %         1 1 l-1 l-1;
                      %         1 1 1 1];
                      %sup_r = T*sup_o;
                      %sup_r = sup_r./sup_r(3,:);
                      %dim_r_k = floor(max(sup_r(2,:)))*1;

% p0 é matriz de pontos de entrada da imagem
p0 = [1 1 50 50;
      1 350 1 300;
      390 1 390 1;
      390 350 300 350];
      
arq = "dog.png";

% T = [1 0 0; 0 1 0; 0.001 0.001 1];

Ti = inv(T);

% arq é a imagem que será lida 
img = imread(arq);
img = rgb2gray(img);
img = im2double(img);
[l c] = size(img);
new_img = zeros(l, c);
new_img = uint8(new_img);
figure('Name','Figura Original','NumberTitle','off');
imshow(img);

% A seguir, os elementos são retirados um a um da matriz de entrada
% Os elementos com L na variável são pontos da imagem distorcida
x0 = p0(1,1); % (linha, coluna)
x1 = p0(2,1);
x2 = p0(3,1);
x3 = p0(4,1);
y0 = p0(1,2);
y1 = p0(2,2);
y2 = p0(3,2);
y3 = p0(4,2);
x0L = p0(1,3);
x1L = p0(2,3);
x2L = p0(3,3);
x3L = p0(4,3);
y0L = p0(1,4);
y1L = p0(2,4);
y2L = p0(3,4);
y3L = p0(4,4);

% Matriz dos coeficientes (sistema de equações)  
A = [x0 y0 1 0 0 0 (-1)*x0*x0L (-1)*y0*x0L;
     0 0 0 x0 y0 1 (-1)*x0*y0L (-1)*y0*y0L;
     x1 y1 1 0 0 0 (-1)*x1*x1L (-1)*y1*x1L;
     0 0 0 x1 y1 1 (-1)*x1*y1L (-1)*y1*y1L;
     x2 y2 1 0 0 0 (-1)*x2*x2L (-1)*y2*x2L;
     0 0 0 x2 y2 1 (-1)*x2*y2L (-1)*y2*y2L;
     x3 y3 1 0 0 0 (-1)*x3*x3L (-1)*y3*x3L;
     0 0 0 x3 y3 1 (-1)*x3*y3L (-1)*y3*y3L];

% Matriz dos coeficientes (transformação projetiva)  
L = [x0L; y0L; x1L; y1L; x2L; y2L; x3L; y3L];

% Matriz de observações  
% x = (At . A)^-1 . At . L
x = inv((A.')*A)*((A.')*L);
% Se A.' não der certo, testar A'

% Queremos obter a matriz de transformação 3 x 3 a partir dos elementos de x (há apenas 8 elementos em x)
% Para isso, deve-se preencher o último elemento com "1"

% Matriz de Transformação
T = [x(1,1) x(2,1) x(3,1); 
     x(4,1) x(5,1) x(6,1); 
     x(7,1) x(8,1) 1];

% Matrizes Cn que serão multiplicadas por T para normalizá-la  
C0 = [x0; y0; 1]; % [xk yk 1], sendo k = 0
C1 = [x1; y1; 1]; % [xk+1 yk+1 1] 
C2 = [x2; y2; 1]; % [xk+2 yk+2 1]  
C3 = [x3; y3; 1]; % [xk+n yk+n 1], sendo n = 3 

% Matriz 3x3 * Matriz 3x1 = Matriz 3x1
T0 = T*C0; % Coluna 1 da matriz
T1 = T*C1;
T2 = T*C2;
T3 = T*C3;

z0 = T0(3, 1); % Removendo zk de cada matriz para normalizar T
z1 = T1(3, 1);
z2 = T2(3, 1);
z3 = T3(3, 1);

T0 = T0/z0; % T0, T1, T2 e T3 são matrizes 3x1
T1 = T1/z1;
T2 = T2/z2;
T3 = T3/z3;

% Unimos as 4 matrizes, formando a matriz de transformação 3x4 normalizada
Tn = horzcat(T0, T1, T2, T3);
% A normalização das coordenadas serve para que vire um plano afim, para que possa usar as propriedades e transformações afins
%disp(Tn);
%theta = -0.78539816339744830961566084581988; % 45 degrees
%centerX = 153;
%centerY = 105;
for x=1 : c
   for y=1 : l
      new_img(0,0) = img(x, y);
      new_img(1,0) = img(x+1, y);
      new_img(0,1) = img(x, y+1);
      new_img(1,1) = img(x+1, y+1);
      v = floor(x) - x; % obtém apenas a parte decimal que "sobra" de um pixel inteiro
      u = floor(y) - y;
      new_img(x,y) = ceil((1-u)*(1-v)*(img(0,0) + (1-u)*v*img(1,0) + u*(1-v)*img(0,1) + u*v*img(1,1));
       % From screen system to center system
       % Center coordinate system
       cx = x-centerX;
       cy = centerY-y;
       % Rotate
       nx = cx*cos(theta)-cy*sin(theta);
       ny = cx*sin(theta)+cy*cos(theta);
       % Return old system
       cx=nx+centerX;
       cy=centerY-ny;
       % Pick up neighbors coordinates origin and float value of coordinate
       Pox = floor(cx);
       Poy = floor(cy);
       xn = cx-floor(cx);
       yn = cy-floor(cy);
       if (cx>1)
         if (cy>1)
           if (cx<b)
             if (cy<a)
                % Bilinear
                br2(y,x,1) = ceil(br(Poy,Pox,1)*(1-xn)*(1-yn)+br(Poy,Pox+1,1)*xn*(1-yn)+br(Poy+1,Pox,1)*(1-xn)*yn+br(Poy+1,Pox+1,1)*xn*yn);
                br2(y,x,2) = ceil(br(Poy,Pox,2)*(1-xn)*(1-yn)+br(Poy,Pox+1,2)*xn*(1-yn)+br(Poy+1,Pox,2)*(1-xn)*yn+br(Poy+1,Pox+1,2)*xn*yn);
                br2(y,x,3) = ceil(br(Poy,Pox,3)*(1-xn)*(1-yn)+br(Poy,Pox+1,3)*xn*(1-yn)+br(Poy+1,Pox,3)*(1-xn)*yn+br(Poy+1,Pox+1,3)*xn*yn);
              endif
            endif
          endif
       endif
   endfor;
endfor;
figure;
imshow(br2);