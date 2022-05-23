%Script Geral
pkg load image; 
resp = 'S';
	while resp == 'S' || resp == 's',
		loop = 1;
		arq = input('Insira o nome de arquivo de uma imagem entre aspas: ');

		if ~exist(arq, 'file')
      loop = 0;
			errorMessage = sprintf('Erro: o arquivo %s nao existe no diretorio atual.', arq);
			uiwait(warndlg(errorMessage));
			return;
		endif
    
		img = imread(arq);
			while loop == 1,
				filtro = input('Deseja utilizar qual filtro? [1 - Movimento / 2 - Laplaciano / 3 - Diminuicao de Nitidez] ');
					if (filtro == 1)
						f = fspecial('motion', 50, 45);
						loop = 0;
					elseif (filtro == 2)
						f = fspecial('laplacian', 0.1);
						loop = 0;
					elseif (filtro == 3)
						f = fspecial('unsharp', 0.2);
						loop = 0;
					else
						disp('Favor inserir: 1, 2 ou 3.');
						loop = 1;						
					endif
			endwhile
						
			R = img(:, :, 1);
			G = img(:, :, 2);
			B = img(:, :, 3);
			I1 = imfilter(R, f);
			I2 = imfilter(G, f);
			I3 = imfilter(B, f);
			new_img = cat(3, I1, I2, I3);
			figure('Name','Filtro','NumberTitle','off')
			subplot(2,2,[1,2]);
			imshow(img)
			subplot(2,2,[3,4]);
			imshow(new_img)
			resp = input('Deseja inserir nova foto? (S/N) ', ' ');
	endwhile
disp('Tchau!'); 