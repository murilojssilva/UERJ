%Script
pkg load image; 
resp = 'S';
	while resp == 'S' || resp == 's',
		arq = input('Insira o nome de arquivo de uma imagem entre aspas: ');
		
		if ~exist(arq, 'file')
    	resp = 'N';
			errorMessage = sprintf('Erro: o arquivo %s nao existe no diretorio atual.', arq);
			uiwait(warndlg(errorMessage));
			return;
		endif
		
		img = imread(arq);
		f = ones(5,5) / 25;
		R = img(:, :, 1);
		G = img(:, :, 2);
		B = img(:, :, 3);
		I1 = imfilter(R, f);
		I2 = imfilter(G, f);
		I3 = imfilter(B, f);
		new_img = cat(3, I1, I2, I3);
		figure('Name','Suavizacao Linear - Filtro de Media','NumberTitle','off')
		subplot(2,2,[1,2]);
		imshow(img)
		subplot(2,2,[3,4]);
		imshow(new_img)
		resp = input('Deseja inserir nova foto? (S/N) ', ' ');
	endwhile
disp('Tchau!'); 