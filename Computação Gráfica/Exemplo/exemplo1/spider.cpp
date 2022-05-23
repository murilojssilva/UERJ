#include<GL/glut.h>
#include<vector>
#include<cmath>
#include "spider.h"

/*
Trabalho de computacao grafica parte 1 de:
	David Souza Rodrigues 4461180
	Gabriel Toschi de Oliveira 9763039
	Marcelo de Moraes Carvalho da Silva 9791048
	Marcos Wendell Souza de Oliveira Santos 9791351
*/
using namespace std;

//vetores com coordenadas dos centros das partes do corpo da aranha para inicializacao
GLint bodyPartX[NUMBER_OF_BODY_PARTS] = {CEPHALOTHORAX_X, ABDOMEN_X, LEFT_EYE_X, RIGHT_EYE_X},
	  bodyPartY[NUMBER_OF_BODY_PARTS] = {CEPHALOTHORAX_Y, ABDOMEN_Y, LEFT_EYE_Y, RIGHT_EYE_Y};

//vetores com raios das partes do corpo da aranha para inicializacao
GLint bodyPartSizesX[NUMBER_OF_BODY_PARTS] = {CEPHALOTHORAX_X_RADIUS, ABDOMEN_X_RADIUS, LEFT_EYE_X_RADIUS, RIGHT_EYE_X_RADIUS},
	  bodyPartSizesY[NUMBER_OF_BODY_PARTS] = {CEPHALOTHORAX_Y_RADIUS, ABDOMEN_Y_RADIUS, LEFT_EYE_Y_RADIUS, RIGHT_EYE_Y_RADIUS};

//matrizes com as posicoes iniciais dos pontos de articulacao das pernas para incializacao
GLint legsX[NUMBER_OF_ARTICULATIONS + 1][NUMBER_OF_LEGS] = { {LEG_1_P1_X, LEG_2_P1_X, LEG_3_P1_X, LEG_4_P1_X, LEG_5_P1_X, LEG_6_P1_X, LEG_7_P1_X, LEG_8_P1_X} ,
															 {LEG_1_P2_X, LEG_2_P2_X, LEG_3_P2_X, LEG_4_P2_X, LEG_5_P2_X, LEG_6_P2_X, LEG_7_P2_X, LEG_8_P2_X} },
	  legsY[NUMBER_OF_ARTICULATIONS + 1][NUMBER_OF_LEGS] = { {LEG_1_P1_Y, LEG_2_P1_Y, LEG_3_P1_Y, LEG_4_P1_Y, LEG_5_P1_Y, LEG_6_P1_Y, LEG_7_P1_Y, LEG_8_P1_Y} ,

			     											 {LEG_1_P2_Y, LEG_2_P2_Y, LEG_3_P2_Y, LEG_4_P2_Y, LEG_5_P2_Y, LEG_6_P2_Y, LEG_7_P2_Y, LEG_8_P2_Y} };
//vetor com os pontos de conexao das paernas ao cefalotorax para inicializacao
GLint attachPoints[NUMBER_OF_LEGS] = {LEG_1_ATTACH_POINT, LEG_2_ATTACH_POINT, LEG_3_ATTACH_POINT, LEG_4_ATTACH_POINT, LEG_5_ATTACH_POINT, LEG_6_ATTACH_POINT, LEG_7_ATTACH_POINT, LEG_8_ATTACH_POINT};

//matrizes com os valores para um passo da animacao das pernas da aranha
//para calculo do tamanho do passo dividide-se a rotacao pelo numero de passos, e calcula-se a raiz n-esima do valor de escala, onde n eh o numero de passos da animacao
GLfloat legs_rotation1[NUMBER_OF_ARTICULATIONS+1][NUMBER_OF_LEGS] = { {LEG_1_P1_ROTATION1/LEGS_ANIMATION_STEPS, LEG_2_P1_ROTATION1/LEGS_ANIMATION_STEPS, LEG_3_P1_ROTATION1/LEGS_ANIMATION_STEPS, LEG_4_P1_ROTATION1/LEGS_ANIMATION_STEPS, LEG_5_P1_ROTATION1/LEGS_ANIMATION_STEPS, LEG_6_P1_ROTATION1/LEGS_ANIMATION_STEPS, LEG_7_P1_ROTATION1/LEGS_ANIMATION_STEPS, LEG_8_P1_ROTATION1/LEGS_ANIMATION_STEPS} ,
															          {LEG_1_P2_ROTATION1/LEGS_ANIMATION_STEPS, LEG_2_P2_ROTATION1/LEGS_ANIMATION_STEPS, LEG_3_P2_ROTATION1/LEGS_ANIMATION_STEPS, LEG_4_P2_ROTATION1/LEGS_ANIMATION_STEPS, LEG_5_P2_ROTATION1/LEGS_ANIMATION_STEPS, LEG_6_P2_ROTATION1/LEGS_ANIMATION_STEPS, LEG_7_P2_ROTATION1/LEGS_ANIMATION_STEPS, LEG_8_P2_ROTATION1/LEGS_ANIMATION_STEPS} },
		legs_scale1[NUMBER_OF_ARTICULATIONS+1][NUMBER_OF_LEGS]    = { {pow(LEG_1_P1_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_2_P1_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_3_P1_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_4_P1_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_5_P1_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_6_P1_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_7_P1_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_8_P1_SCALE1,1.0/LEGS_ANIMATION_STEPS)} ,
															          {pow(LEG_1_P2_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_2_P2_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_3_P2_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_4_P2_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_5_P2_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_6_P2_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_7_P2_SCALE1,1.0/LEGS_ANIMATION_STEPS), pow(LEG_8_P2_SCALE1,1.0/LEGS_ANIMATION_STEPS)} },
		legs_rotation2[NUMBER_OF_ARTICULATIONS+1][NUMBER_OF_LEGS] = { {LEG_1_P1_ROTATION2/LEGS_ANIMATION_STEPS, LEG_2_P1_ROTATION2/LEGS_ANIMATION_STEPS, LEG_3_P1_ROTATION2/LEGS_ANIMATION_STEPS, LEG_4_P1_ROTATION2/LEGS_ANIMATION_STEPS, LEG_5_P1_ROTATION2/LEGS_ANIMATION_STEPS, LEG_6_P1_ROTATION2/LEGS_ANIMATION_STEPS, LEG_7_P1_ROTATION2/LEGS_ANIMATION_STEPS, LEG_8_P1_ROTATION2/LEGS_ANIMATION_STEPS} ,
															          {LEG_1_P2_ROTATION2/LEGS_ANIMATION_STEPS, LEG_2_P2_ROTATION2/LEGS_ANIMATION_STEPS, LEG_3_P2_ROTATION2/LEGS_ANIMATION_STEPS, LEG_4_P2_ROTATION2/LEGS_ANIMATION_STEPS, LEG_5_P2_ROTATION2/LEGS_ANIMATION_STEPS, LEG_6_P2_ROTATION2/LEGS_ANIMATION_STEPS, LEG_7_P2_ROTATION2/LEGS_ANIMATION_STEPS, LEG_8_P2_ROTATION2/LEGS_ANIMATION_STEPS} },
		legs_scale2[NUMBER_OF_ARTICULATIONS+1][NUMBER_OF_LEGS]    = { {pow(LEG_1_P1_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_2_P1_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_3_P1_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_4_P1_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_5_P1_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_6_P1_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_7_P1_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_8_P1_SCALE2,1.0/LEGS_ANIMATION_STEPS)} ,
															          {pow(LEG_1_P2_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_2_P2_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_3_P2_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_4_P2_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_5_P2_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_6_P2_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_7_P2_SCALE2,1.0/LEGS_ANIMATION_STEPS), pow(LEG_8_P2_SCALE2,1.0/LEGS_ANIMATION_STEPS)} };

vector<bodyPart> body;//vetor que armazena as partes do corpo da aranha
vector<leg> legs;//vetor que armazena as pernas da aranha
bool canWalk;//variavel para controle da animacao, a aranha nao pode receber um novo destino ate que alcance o anteriormente passado

//variaveis para localizacao da aranha
vec2D orientation;//vetor que representa o orientacao da aranha
point center;//posicao do centro da aranha

//variaveis para animacao do corpo da aranha
GLfloat finalAngle;//angulo(em realcao a posicao em que estava anteriormente) que a aranha deve estar ao final de sua animacao de rotacao
int translationSteps;//numero de passos que devem ser feitos para que a aranha complete sua animacao de translacao
point dest;//ponto destino da aranha

//variaveis para animacao das pernas da aranha
int legsAnimationStep = 0;//passo atual da animacao das pernas
int legsAnimationSpeed = 1;//velocidade da animacao das pernas, eh utilizada apenas com os valores 1 e -1  para variacao de legsAnimationStep de -LEGS_ANIMATION_STEPS ate LEGS_ANIMATION_STEPS
bool invertTransformation;//variavel utilizada para invercao da animacao das pernas da aranha
int legsAnimationOption = 1;//opcao de animcao das pernas da aranha

//variaveis para incializacao da janela
GLint WINDOW_WIDTH  = 700,//largura da janela
      WINDOW_HEIGHT = 700;//altura da janela


int main(int argc, char *argv[]){

	glutInit(&argc,argv);//inicializacao da biblioteca GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//incializacao do modo de display, GLUT_RGB para o sistema de cores e GLUT_SINGLE para o numero de buffers

	GLint screen_width  = glutGet(GLUT_SCREEN_WIDTH),//obtencao da largura da tela do computador
          screen_height = glutGet(GLUT_SCREEN_HEIGHT);//obtencao da altura da tela do computador
  
 	glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);//inicializacao da posicao da janela no meio da tela do computador
  	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);//inicializacao do tamanho da janela
  	glutCreateWindow("Spider");//criacao da janela com o nome de "Spider"

  	init();//inicializacao da cena
  	glutDisplayFunc(display);//definicao para a biblioteca GLUT qual funcao tratara do display da cena
  	glutMouseFunc(mouse);//definicao para a biblioteca GLUT qual funcao tratara da entrada do mouse

  	glutMainLoop();//inicializacao do loop principal da biblioteca GLUT

	return EXIT_SUCCESS;
}

/**/
//init
//funcao que inicializa a cena
/**/
void init(){
	glClearColor(0,0,0,1);//definicao da cor de clear como branco
	glMatrixMode(GL_PROJECTION);//inicializacao do modo da matriz como matriz de projecao
	gluOrtho2D(-WINDOW_WIDTH/2, WINDOW_WIDTH/2, -WINDOW_HEIGHT/2, WINDOW_HEIGHT/2);//inicializacao do sistema de coordenadas da cena
	glClear(GL_COLOR_BUFFER_BIT);//limpeza da janela com a cor de clear pre-definida
	glColor3f(0,1,0);//definicao da cor para desenho como preto
	glLineWidth(LINE_SIZE);//definicao da largura das linhas a denhar
	build_body();//construcao do corpo da aranha
	build_legs();//construcao das pernas da aranha
	canWalk = true;//
	orientation.x = CEPHALOTHORAX_X - ABDOMEN_X;//inicializacao da coordenada x da orientacao da aranha
	orientation.y = CEPHALOTHORAX_Y - ABDOMEN_Y;//inicializacao da coordenada y da orientacao da aranha
	GLfloat aux = norm(orientation);//calculo da norma euclidiana do vetor orientacao
	orientation.x /= aux;//normalizacao da coordenada x do vetor de orientacao
	orientation.y /= aux;//normalizacao da coordenada y do vetor de orientacao
	center.x = CEPHALOTHORAX_X;//definicao da coordenada x do centro da aranha
	center.y = CEPHALOTHORAX_Y;//definicao da coordenada y do centro da aranha
}

/**/
//display
//funcao que trata o display da aranha na cena
/**/
void display(){
	glClear(GL_COLOR_BUFFER_BIT);//limpeza da janela com a cor de clear pre-definida
	draw_legs();//funcao que desenha as pernas da aranha
	draw_body();//funcao que desenha o corpo da aranha
	glFlush();//funcao que forca a execucao de todos os comandos que tenham sido passados para o Open GL e ainda nao tenham sido executados
}

/**/
//mouse
//funcao que trata a entrada do mouse
//params:
// - button: GLint, botao do mouse que executou a acao
// - action: GLint, acao que o botao realizou
// - x: GLint, posicao da coordenada x do mouse em relacao a janela
// - y: GLint, posicao da coordenada y do mouse em relacao a janela
/**/
void mouse(GLint button, GLint action, GLint x, GLint y){
	if(action == GLUT_DOWN && button == GLUT_LEFT_BUTTON && canWalk){//se o botao esquerdo do mouse for precionado e aranha puder andar
		x = x - WINDOW_WIDTH/2;//cacula-se a posicao da coordenada x em relacao a cena ao inves da janela
		y = WINDOW_HEIGHT/2 - y;//calcula-se a posicao da coordena y em relacao a cena ao inves da janela
		if(x != center.x && y != center.y){//se o ponto selecionado nao for o centro da aranha
			canWalk = false;//a aranha fica impossibilitada de receber um novo destino ate que chegue a mais recentemente passado
			vec2D aux;//vetor auxiliar para calculo do angulo de rotacao da aranha
			aux.x = x - center.x;//defnificao da coordenada x do vetor entre o centro da aranha e ponto em que o mouse foi precionado
			aux.y = y - center.y;//defnificao da coordenada y do vetor entre o centro da aranha e ponto em que o mouse foi precionado
			translationSteps = (int) norm(aux)+1;//calculo do numero de passos necessarios para a animacao de translacao da aranha. Pega-se a parte inteiro da norma do vetor auxiliar e soma-se 1
			finalAngle = acos(dot(aux,orientation)/(norm(aux)*norm(orientation)));//calculo do angulo necessario para a animacao de rotacao da aranha. Calcula-se por meio do produto escalar
			finalAngle = vecprod(aux,orientation)>0?-finalAngle:finalAngle;//calulo do sinal do angulo necessario para a animcao de rotacao da aranha. Calcula-se por meio do produto vetorial
			glutTimerFunc(ANIMATION_SPEED,&rotate_spider,abs(finalAngle/ROTATE_STEP_SIZE));//sinalizacao para a biblioteca GLUT que a funcao de animacao de rotacao da aranha deve ser chamada daqui a ANIMATIO_SPEED ms passando o ultimo parametro como argumento
			aux = orientation;//reutilizacao do vetor auxiliar para rotacao do vetor orientacao
			orientation.x = aux.x*cos(finalAngle) - aux.y*sin(finalAngle);//rotacao da coordenada x do vetor de orientacao
			orientation.y = aux.x*sin(finalAngle) + aux.y*cos(finalAngle);//rotacao da coordenada y do vetor de orientacao
			dest.x = x;///a coordenada x do ponto destino da aranha
			dest.y = y;//a coordenada y do ponto destino da aranha
		}
	}
}

/**/
//build_body
//funcao que constroi o corpo da aranha
/**/
void build_body(){
	point p;//ponto para auxiliar na construcao do corpo
	GLfloat x, y;//variaveis para auxiliar nas coordenadas dos centros na construcao do corpo
	GLfloat rx, ry;//variaveis para auxiliar com os raios na construcao do corpo
	GLfloat angle = 2*M_PI/CIRCLE_POINTS;//angulo entre cada angulo das elipses e circulos do corpo da aranha
	body = vector<bodyPart>(NUMBER_OF_BODY_PARTS);//incializacao do vetor que armazena as partes do corpo da aranha

	for(int j = 0; j < NUMBER_OF_BODY_PARTS; j++){//para cada parte do corpo da aranha
		x = bodyPartX[j];//coordenda x do centro dessa paarte do corpo
		y = bodyPartY[j];//coordenda x do centro dessa paarte do corpo
		rx = bodyPartSizesX[j];//raio em x dessa parte do corpo
		ry = bodyPartSizesY[j];//raio em y dessa parte do corpo
		body[j] = bodyPart(CIRCLE_POINTS);//inicializaco de um vetor com CIRCLE_POINTS posicoes
		for(GLint i = 0; i < CIRCLE_POINTS; i++){//calculo das coordenadas dos pontos de um parte do corpo por meio do uso de coordenadas polares
			p.x = x + rx*cos(angle*i);
			p.y = y + ry*sin(angle*i);
			body[j][i] = p;
		}
	}

}

/**/
//build_legs
//funcao que constroi as pernas da aranha
/**/
void build_legs(){
	point a;//ponto para auxiliar a construcao das pernas
	leg aux;//variavel auxiliar para ajudar na construcao das pernas
	for(int i = 0 ; i < NUMBER_OF_LEGS; i++){
		aux.articulations.clear();//limpa-se o vetor com os pontos de articulacao
		aux.attachment = attachPoints[i];//inicializa-se o ponto de conexao da perna
		for(int j = 0; j <= NUMBER_OF_ARTICULATIONS; j++){
			a.x = legsX[j][i];//inicializa-se a coordenada x da perna 
			a.y = legsY[j][i];//inicializa-se a coordenada y da perna
			aux.articulations.push_back(a);//armazena-se o ponto na perna
		}
		legs.push_back(aux);//armazena-se a perna
	}
}

/**/
//draw_legs
//funcao que desenha as pernas da aranha
/**/
void draw_legs(){
	for(int i = 0; i < NUMBER_OF_LEGS; i++){
		glBegin(GL_LINE_STRIP);//inicializacao dos pontos a desenhar com GL_LINE_STRIP, cada ponto passado conecta-se ao anteriormente passado
			glVertex2f(CEPHALOTHORAX[legs[i].attachment].x,CEPHALOTHORAX[legs[i].attachment].y);//comeca-se com o ponto de conexao com o cefalotorax
			for(int j = 0; j < legs[i].articulations.size();j++)
				glVertex2f(legs[i].articulations[j].x,legs[i].articulations[j].y);//passa-se os outros pontos das pernas
		glEnd();//finalizacao do pontos a desenhar
	}

}

/**/
//draw_body
//funcao que desnha o corpo da aranha
/**/
void draw_body(){
	for(int i = 0; i < NUMBER_OF_BODY_PARTS; i++){
		glBegin(GL_LINE_LOOP);//inicializacao dos pontos a desenhar com GL_LINE_LOOP, cada ponto conecta-se ao anteriormente passado e o ultimo ponto passdad conecta-se com o primeiro passado
			for(int j = 0; j < CIRCLE_POINTS; j++)
				glVertex2f(body[i][j].x, body[i][j].y);//passam-se os pontos das partes do corpo
		glEnd();
	}
}

/**/
//rotate_spider
//funcao que faz a animacao de rotacao do corpo da aranha
//params:
// - step: GLint, passo atual da animacao de rotacao do corpo da aranha
/**/
void rotate_spider(GLint step){
	GLfloat rotate_step = finalAngle>0?ROTATE_STEP_SIZE:-ROTATE_STEP_SIZE;//verificacao da direcao da animacao de rotacao do corpo, se o angulo for negativo, sentido horario, e sentido anti-horario caso contrario
	GLfloat mat[9] = matRotate(rotate_step,center.x,center.y);//matriz de rotacao em torno do centro da aranha
	
	GLfloat aux;//variavel utilizada para auxiliar na multiplicacao de matrizes
	for(int i = 0 ; i < NUMBER_OF_BODY_PARTS; i++)
		for(int j = 0 ; j < CIRCLE_POINTS; j++){
			aux = body[i][j].x;//multiplicao de matrizes: a matriz de rotacao vezes as coordenadas dos pontos das partes do corpo
			body[i][j].x = aux*mat[0] + body[i][j].y*mat[3] + mat[6];//como utiliza-se coordenadas homogeneas a coordenada z nao eh multiplicada
			body[i][j].y = aux*mat[1] + body[i][j].y*mat[4] + mat[7];//pois se mantera sempre igual e nao eh interrsessante fazer contas desnecessarias
		}
	for(int i = 0; i < NUMBER_OF_LEGS; i++)
		for(int j = 0; j < NUMBER_OF_ARTICULATIONS+1; j++){
			aux = legs[i].articulations[j].x;//multiplicao de matrizes: a matriz de rotacao vezes as coordenadas dos pontos das pernas da aranha
			legs[i].articulations[j].x = aux*mat[0] + legs[i].articulations[j].y*mat[3] + mat[6];//como utiliza-se coordenadas homogeneas a coordenada z nao eh multiplicada
			legs[i].articulations[j].y = aux*mat[1] + legs[i].articulations[j].y*mat[4] + mat[7];//pois se mantera sempre igual e nao eh interrsessante fazer contas desnecessarias
		}
	move_legs();//funcao de animacao das pernas da aranha
	glutPostRedisplay();//sinalizacao para a biblioteca GLUT para chamer a funcao que cuida do display
	if( step > 0 )//se a animacao de rotacao da aranha ainda nao tiver acabado
		glutTimerFunc(ANIMATION_SPEED,&rotate_spider,step-1);//sinaliza-se para a biblioteca GLUT que deve-se chamar a funcao novamente, mas com um passo a menos
	else{//caso contrario
		glutTimerFunc(ANIMATION_SPEED,&translate_spider,translationSteps);//se a animcao de rotacao acabou, sinaliza-se para a biblioteca GLUT que deve-se chmar a funcao de animcao de translacao da aranha daqui a ANIMATION_SPEED ms passando o ultimo parametro como argumento
		center.x = dest.x;//translacao da coordenada x do centro da aranha
		center.y = dest.y;//translacao da coordenada y do centro da aranha
	}
}

/**/
//translate_spider
//funcao que faz animcao de translacao do corpo da aranha
//params:
// - step: GLint, passo atual da animacao de translacao do corpo da aranha
/**/
void translate_spider(GLint step){
	GLfloat mat[9] = matTranslate(orientation.x,orientation.y);//matriz de translacao
	
	GLfloat aux;//variavel utilizada para auxiliar na multiplicacao de matrizes
	for(int i = 0 ; i < NUMBER_OF_BODY_PARTS; i++)
		for(int j = 0 ; j < CIRCLE_POINTS; j++){
			aux = body[i][j].x;//multiplicao de matrizes: a matriz de translacao vezes as coordenadas dos pontos das partes do corpo
			body[i][j].x = aux*mat[0] + body[i][j].y*mat[3] + mat[6];//como utiliza-se coordenadas homogeneas a coordenada z nao eh multiplicada
			body[i][j].y = aux*mat[1] + body[i][j].y*mat[4] + mat[7];//pois se mantera sempre igual e nao eh interrsessante fazer contas desnecessarias
		}
	for(int i = 0; i < NUMBER_OF_LEGS; i++)
		for(int j = 0; j < NUMBER_OF_ARTICULATIONS+1; j++){
			aux = legs[i].articulations[j].x;//multiplicao de matrizes: a matriz de translacao vezes as coordenadas dos pontos das pernas da aranha
			legs[i].articulations[j].x = aux*mat[0] + legs[i].articulations[j].y*mat[3] + mat[6];//como utiliza-se coordenadas homogeneas a coordenada z nao eh multiplicada
			legs[i].articulations[j].y = aux*mat[1] + legs[i].articulations[j].y*mat[4] + mat[7];//pois se mantera sempre igual e nao eh interrsessante fazer contas desnecessarias
		}
	if( step > 0 ){//se a animacao de translacao da aranha ainda nao tiver acabado
		move_legs();//a funcao de animcao das pernas da aranha eh chamada
		glutTimerFunc(ANIMATION_SPEED,&translate_spider,step-1);//sinaliza-se para a biblioteca GLUT que deve-se chamar a funcao novamente, mas com um passo a menos
	}else{//caso contrario
		restore_legs_position();//chama-se a funcao que restaura a posicao das pernas a posicao que elas estriam se nao tivessem sido animadas
		canWalk = true;//desbloquei-se a entrada de um novo ponto de destino para a aranha
	}
	glutPostRedisplay();//sinalizacao para a biblioteca GLUT para chamer a funcao que cuida do display
}

/**/
//move_legs
//funcao de animcao das pernas da aranha
/**/
void move_legs(){
	if(legsAnimationStep == LEGS_ANIMATION_STEPS){//se o passo da animacao das pernas da aranha for igual a LEGS_ANIMATION_STEPS
		legsAnimationSpeed = -1;//a velocidade de animacao passa a ser -1
		invertTransformation = true;//a transformacao de animacao das pernas da aranha passa ser a inversa
	}else if(legsAnimationStep == -LEGS_ANIMATION_STEPS){//se o passo da animacao das pernas da aranha for igual a -LEGS_ANIMATION_STEPS
		legsAnimationSpeed = 1;//a velocidade de animacao passa a ser 1
		invertTransformation = true;//a transformacao de animacao das pernas da aranha passa ser a inversa
	}else if(legsAnimationStep == 0){//se o passo da animcao das pernas da ranha for ihual a 0
		if(legsAnimationOption  == 1)//se a animacao anterior for a 1
			legsAnimationOption  = 2;//muda-se para a animacao 2
		else//se a animacao anterior for a 2
			legsAnimationOption  = 1;//muda-se para a animacao 1
		invertTransformation = false;//a tranformacao de animacao das pernas da aranha deixa de ser a inversa
	}
	legsAnimationStep += legsAnimationSpeed;//o passo da animacao das pernas da aranha eh incrementado com legsAnimationSpeed
	for(int i = 0; i < NUMBER_OF_LEGS; i++)//para cada perna da aranha chama-se a funcao que anima uma perna da aranha
		move_leg(CEPHALOTHORAX[legs[i].attachment].x,CEPHALOTHORAX[legs[i].attachment].y,0,i);
}

/**/
//move_leg
//funcao recursiva que anima uma perna da aranha
//params:
// - x: GLfloat, coordenada x do ponto fixo na rotacao e escala
// - y: GLfloat, coordenada y do ponto fixo na rotacao e escala
// - step: int, passo da animacao, articulacao atual da perna da aranha que se esta animando
// - current_leg: int, perna atula que se esta animando
/**/
void move_leg(GLfloat x, GLfloat y, int step, int current_leg){
	if(step == NUMBER_OF_ARTICULATIONS+1)//condicao de parada da funcao recursiva
		return;
	GLfloat rotation;//variavel auxiliar para inicializacao da matriz de transformacao
	GLfloat scale;//variavel auxiliar para inicializacao da matriz de transformacao
	switch(legsAnimationOption){
		case 1://caso seja a animacao 1, obtem-se os valores dessa animacao para a perna atual a partir das matrizes correspondentes, e inverte-se a transformcao se necessario
			rotation = invertTransformation?-legs_rotation1[step][current_leg]:legs_rotation1[step][current_leg];
			scale = invertTransformation?1.0/legs_scale1[step][current_leg]:legs_scale1[step][current_leg];
		break;
		case 2://caso seja a animacao 2, obtem-se os valores dessa animacao para a perna atual a partir das matrizes correspondentes, e inverte-se a transformcao se necessario
			rotation = invertTransformation?-legs_rotation2[step][current_leg]:legs_rotation2[step][current_leg];
			scale = invertTransformation?1.0/legs_scale2[step][current_leg]:legs_scale2[step][current_leg];
		break;
	}
	GLfloat mat[9] = matRotateAndScale(rotation, x, y, scale);//matriz que eh concatencao de 4 transformacao que foram feitas nessa ordem: translacao para a origem, rotacao, escala, translacao para as coordenadas originais do ponto fixo

	GLfloat aux;//variavel utilizada para auxiliar na multiplicacao de matrizes
	for(int j = step; j < NUMBER_OF_ARTICULATIONS+1; j++){
		aux = legs[current_leg].articulations[j].x;//multiplicao de matrizes: a matriz de transformacao vezes as coordenadas dos pontos da perna da aranha que sao afetados por essa transformacao
		legs[current_leg].articulations[j].x = aux*mat[0] + legs[current_leg].articulations[j].y*mat[3] + mat[6];//como utiliza-se coordenadas homogeneas a coordenada z nao eh multiplicada
		legs[current_leg].articulations[j].y = aux*mat[1] + legs[current_leg].articulations[j].y*mat[4] + mat[7];//pois se mantera sempre igual e nao eh interrsessante fazer contas desnecessarias
	}

	move_leg(legs[current_leg].articulations[step].x,legs[current_leg].articulations[step].y,step+1,current_leg);//chama-se recursivamente a funcao novamente somando-se um passo a mais 
}

/**/
//restor_legs_position
//funcao que restaura a posicao das pernas da aranha
/**/
void restore_legs_position(){
	if(legsAnimationStep != 0){//se as pernas ja nao estiverem na posicao correta
		if((legsAnimationSpeed > 0 && legsAnimationStep > 0 ) || (legsAnimationSpeed < 0 && legsAnimationStep < 0))//se necessario inverter a transformcao para restaurar a posicao das pernas da aranha
			invertTransformation = !invertTransformation;
		for(int i = 0; i < NUMBER_OF_LEGS; i++)//chama-se a funcao que restaura a posicao de uma perna da aranha para cada perna da aranha
			restore_leg_position(CEPHALOTHORAX[legs[i].attachment].x,CEPHALOTHORAX[legs[i].attachment].y,0,i, abs(legsAnimationStep));
	}
	legsAnimationOption  = 1;//defini-se a opcao de animacao das pernas da aranha como a 1
	invertTransformation = false;//a inversao da animcao das pernas da aranha eh cancelada
	legsAnimationStep = 0;//o passa da animcao das pernas da aranha eh reinicializado
	legsAnimationSpeed = 1;//a velocidade da animcao das pernas da aranha eh reinicializada
}

/**/
//restore_leg_position
//funcao recursiva que restaura a posicao de uma perna da aranha
//params:
// - x: GLfloat, coordenada x do ponto fixo na rotacao e escala
// - y: GLfloat, coordenada y do ponto fixo na rotacao e escala
// - step: int, passo da animacao, articulacao atual da perna da aranha que se esta animando
// - current_leg: int, perna atula que se esta animando
// - multipleSteps: int, numero de passos que seriam necessarios para restaurar a posicao das pernas se fosse utilizada a funcao de animacao das pernas da aranha
/**/
void restore_leg_position(GLfloat x, GLfloat y, int step, int current_leg, int multipleSteps){
	if(step == NUMBER_OF_ARTICULATIONS+1)//condicao de parada da funcao recursiva
		return;
	GLfloat rotation;//variavel auxiliar para inicializacao da matriz de transformacao
	GLfloat scale;//variavel auxiliar para inicializacao da matriz de transformacao
	switch(legsAnimationOption){
		case 1://caso seja a animacao 1, obtem-se os valores dessa animacao para a perna atual a partir das matrizes correspondentes, e inverte-se a transformcao se necessario
			rotation = invertTransformation?-legs_rotation1[step][current_leg]:legs_rotation1[step][current_leg];
			scale = invertTransformation?1.0/legs_scale1[step][current_leg]:legs_scale1[step][current_leg];
		break;
		case 2://caso seja a animacao 2, obtem-se os valores dessa animacao para a perna atual a partir das matrizes correspondentes, e inverte-se a transformcao se necessario
			rotation = invertTransformation?-legs_rotation2[step][current_leg]:legs_rotation2[step][current_leg];
			scale = invertTransformation?1.0/legs_scale2[step][current_leg]:legs_scale2[step][current_leg];
		break;
	}
	rotation *= multipleSteps;//multiplica-se o angulo para realizar uma transformcao apenas ao inves de varias pequenas
	scale = pow(scale,(float) multipleSteps);//eleva-se a escala para realizar uma transformcao apenas ao inves de varias pequenas
	GLfloat mat[9] = matRotateAndScale(rotation, x, y, scale);//matriz que eh concatencao de 4 transformacao que foram feitas nessa ordem: translacao para a origem, rotacao, escala, translacao para as coordenadas originais do ponto fixo

	GLfloat aux;//variavel utilizada para auxiliar na multiplicacao de matrizes
	for(int j = step; j < NUMBER_OF_ARTICULATIONS+1; j++){
		aux = legs[current_leg].articulations[j].x;//multiplicao de matrizes: a matriz de transformacao vezes as coordenadas dos pontos da perna da aranha que sao afetados por essa transformacao
		legs[current_leg].articulations[j].x = aux*mat[0] + legs[current_leg].articulations[j].y*mat[3] + mat[6];//como utiliza-se coordenadas homogeneas a coordenada z nao eh multiplicada
		legs[current_leg].articulations[j].y = aux*mat[1] + legs[current_leg].articulations[j].y*mat[4] + mat[7];//pois se mantera sempre igual e nao eh interrsessante fazer contas desnecessarias
	}

	restore_leg_position(legs[current_leg].articulations[step].x,legs[current_leg].articulations[step].y,step+1,current_leg, multipleSteps);//chama-se recursivamente a funcao novamente somando-se um passo a mais 
}