function rotacao(alpha, p0)

  pkg load image;
  % alpha recebe o ângulo de rotação em graus
  % p0 recebe a matriz que contém os pontos do retângulo que se deseja rotacionar
  % R recebe a matriz de rotação
  R = [cosd(alpha) -sind(alpha) 0; sind(alpha) cosd(alpha) 0; 0 0 1];
 
  % Agora iremos extrair células específicas da matriz que o usuário inseriu para calcular o ponto médio do retângulo
  % O ponto médio é necessário para fazer as matrizes de translação
  % Considerando que o usuário insira os pontos de x na primeira dimensão e de y na segunda, p0 de forma genérica seria:
  % p0 = [x1 x2 x2 x1; y1 y1 y2 y2; 1 1 1 1];
  
  x1 = p0(1, 1); % linha 1, coluna 1
  x2 = p0(1, 2); % linha 1, coluna 2  
  y1 = p0(2, 1); % linha 2, coluna 1  
  y2 = p0(2, 3); % linha 2, coluna 3

  % (tx, ty) será o ponto médio do retângulo inserido pelo usuário 
  tx = (x2 + x1)/2;
  ty = (y2 + y1)/2; 
  
  % T1 recebe a primeira matriz de translação
  T1 = [1 0 (-1)*tx; 0 1 (-1)*ty; 0 0 1];
  % T2 recebe a segunda matriz de translação
  T2 = [1 0 tx; 0 1 ty; 0 0 1];

  % Definindo o gráfico para o retângulo original
  figure('Name','Retangulo Original','NumberTitle','off');
  axis([-5 5 -5 5]);
  hold on;
  line([0 0], [-5 5], 'LineWidth', 1, 'LineStyle', '-'); 
  line([-5 5], [0 0], 'LineWidth', 1, 'LineStyle', '-'); 

  % Desenho das linhas do retângulo original
  line([p0(1, 1) p0(1, 2)], [p0(2, 1) p0(2, 2)], 'LineWidth', 2, 'LineStyle', '-');
  line([p0(1, 2) p0(1, 3)], [p0(2, 2) p0(2, 3)], 'LineWidth', 2, 'LineStyle', '-');
  line([p0(1, 3) p0(1, 4)], [p0(2, 3) p0(2, 4)], 'LineWidth', 2, 'LineStyle', '-');
  line([p0(1, 4) p0(1, 1)], [p0(2, 4) p0(2, 1)], 'LineWidth', 2, 'LineStyle', '-');
  hold off;
  
  % Definindo o gráfico para o retângulo rotacionado
  figure('Name','Retagulo Rotacionado','NumberTitle','off');
  axis([-5 5 -5 5]);
  hold on;
  line([0 0], [-5 5], 'LineWidth', 1, 'LineStyle', '-'); 
  line([-5 5], [0 0], 'LineWidth', 1, 'LineStyle', '-');

  % As duas translações com valores opostos de tx e ty (3.5 e -3.5, 0.5 e -0.5) se cancelam, deixando apenas o retângulo rotacionado
  % Primeiro T1, depois R, depois T2  
  pT = T2*(R*(T1*p0));
  
  % Desenho das linhas do retângulo transformado
  line([pT(1, 1) pT(1, 2)], [pT(2, 1) pT(2, 2)], 'LineWidth', 2, 'LineStyle', '-');
  line([pT(1, 2) pT(1, 3)], [pT(2, 2) pT(2, 3)], 'LineWidth', 2, 'LineStyle', '-');
  line([pT(1, 3) pT(1, 4)], [pT(2, 3) pT(2, 4)], 'LineWidth', 2, 'LineStyle', '-');
  line([pT(1, 4) pT(1, 1)], [pT(2, 4) pT(2, 1)], 'LineWidth', 2, 'LineStyle', '-');
  hold off;
  
endfunction


% Para executar a função, digite na Janela de Comandos:
% rotacao(45, [3.0 4.0 4.0 3.0; 0.0 0.0 1.0 1.0; 1.0 1.0 1.0 1.0]);  
% Onde alpha = 45 e p0 = [3.0 4.0 4.0 3.0; 0.0 0.0 1.0 1.0; 1.0 1.0 1.0 1.0]

% Outro exemplo de execução:
% rotacao(45, [0 1 1 0; 0 0 1 1; 1 1 1 1]);
% Onde alpha = 45 e p0 = [0 1 1 0; 0 0 1 1; 1 1 1 1]

% Mais um exemplo de execução (agora um retângulo):
% rotacao(90, [1 5 5 1; 0 0 2 2; 1 1 1 1]);
% Onde alpha = 90 e p0 = [1 5 5 1; 0 0 2 2; 1 1 1 1]