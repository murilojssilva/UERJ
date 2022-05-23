#ifndef _SPIDER_H_
#define _SPIDER_H_

/*
Trabalho de computacao grafica parte 1 de:
	David Souza Rodrigues 4461180
	Gabriel Toschi de Oliveira 9763039
	Marcelo de Moraes Carvalho da Silva 9791048
	Marcos Wendell Souza de Oliveira Santos 9791351
*/

#include<vector>

using namespace std;

typedef struct{
	GLfloat x,y;//coordenadas x e y de um ponto (float)
}point;//definicao de um ponto

typedef point vec2D;//definicao de um vetor 2D, assim como um ponto um vetor 2D tem duas coordenadas (x e y) para sua representação

typedef struct{
	vector<point> articulations;//vetor para guardar os pontos que representam as articulacoes de uma perna
	GLint attachment;//posicao em que a perna se liga ao cefalotorax. Eh o posicao no vetor de pontos que representa o cefalotorax
}leg;//definicao de uma perna. Conjunto de articulacoes mais ligacao com ocefalotorax

typedef vector<point> bodyPart;//definicao de uma parte do corpo da aranha (pernas nao inclusas). Sao definidas por um conjunto de pontos

void init();//funcao de inicializacao da cena
void display();//funcao que trata do display da aranha na cena
void mouse(GLint, GLint, GLint, GLint);//funcao que trata a entrada do mouse

void build_body();//funcao que constroi o corpo da aranha (Abdomen, Cefalotorax, Olho direito e Olho esquerdo)
void build_legs();//funcao que constroi as pernas da aranhas
void draw_legs();//funcao que desenha as pernas da aranha
void draw_body();//funcao que desenha o corpo da aranha (Abdomen, Cefalotorax, Olho direito e Olho esquerdo)

void rotate_spider(GLint);//funcao que rotaciona a aranha em torno do centro
void translate_spider(GLint);//funcao que translada a aranha
void move_legs();//funcao que move as pernas da aranha
void move_leg(GLfloat, GLfloat, int, int);//funcao que move uma perna da aranha
void restore_legs_position();//funcao que restaura a posicao das pernas da aranha
void restore_leg_position(GLfloat, GLfloat, int, int, int);//funcao que restaura a posicao de uma perna da aranha

#define matRotate(a,x,y) {cos(a),sin(a),0,-sin(a),cos(a),0,x-x*cos(a)+y*sin(a),y-y*cos(a)-x*sin(a),1}//matriz de rotacao em a angulos em torno do ponto de coordenadas x e y
#define matRotateAndScale(a,x,y,s) {s*cos(a),s*sin(a),0,-s*sin(a),s*cos(a),0,x-s*x*cos(a)+s*y*sin(a),y-s*y*cos(a)-s*x*sin(a),1}//matriz de rotacao e escala em a angulos, escalando s uniformemente em torno do ponto de coordenadas x e y
#define matTranslate(x,y) {1,0,0,0,1,0,x,y,1}//matriz de translacao em x e y

#define norm(a) sqrt(a.x*a.x+a.y*a.y)//definicao da norma euclidiana de um vetor (raiz quadrada da soma dos quadrados das coordenadas)
#define dot(a,b) (a.x*b.x+a.y*b.y)//definicao de produto escalar entre dois vetores (somatorio das multiplicaoes das coordenadas)
#define vecprod(a,b) (a.x*b.y-a.y*b.x)//definicao da norma do produto vetorial em tres dimesoes de 2 vetores quando a a coordenada z vale 0

#define ROTATE_STEP_SIZE (GLfloat)(M_PI/180.0)//definicao do tamanho de um passo de rotacao (1 grau) em radianos para animcao
#define CIRCLE_POINTS 90//definicao do numero de pontos que utilizacao para representar um circulo ou elipse
#define TRANSLATE_STEP_SIZE 1//definicao do tamanho de um passa de translacao para animcao

#define LINE_SIZE 1//definicao da largura de  uma linha
#define ANIMATION_SPEED 10//definicao do tempo de animcao em milisegundos
#define LEGS_ANIMATION_STEPS 30//definicao do numero de passos utilizados para animar o movimento completo das pernas



#define NUMBER_OF_BODY_PARTS 4//numero de partes que compoem um corpo

#define CEPHALOTHORAX body[0]//cefalotorax da aranha
#define CEPHALOTHORAX_X 0//coordenada x do centro do cefalotorax
#define CEPHALOTHORAX_Y 0//coordenada y do centro do cefalotorax
#define CEPHALOTHORAX_X_RADIUS 30//raio x do cefalotorax
#define CEPHALOTHORAX_Y_RADIUS 30//raio y do cefalotorax

#define ABDOMEN_X 0//coordenada x do centro do abdomen
#define ABDOMEN_Y -75//coordenada y do centro do abdomen
#define ABDOMEN_X_RADIUS 45//raio x do abdomen
#define ABDOMEN_Y_RADIUS 45//raio y do abdomen

#define LEFT_EYE_X -5//coordenada x do centro do olho esquerdo
#define LEFT_EYE_Y 20//coordenada y do centro do olho esquerdo
#define LEFT_EYE_X_RADIUS 4//raio x do olho esquerdo
#define LEFT_EYE_Y_RADIUS 8//raio y do olho esuqerdo

#define RIGHT_EYE_X 5//coordenada x do centro do olho direito
#define RIGHT_EYE_Y 20//coordenada y do centro do olho direito
#define RIGHT_EYE_X_RADIUS 4//raio x do olho direito
#define RIGHT_EYE_Y_RADIUS 8//raio y do olho direito



#define NUMBER_OF_LEGS 8//numero de pernas de uma aranha
#define NUMBER_OF_ARTICULATIONS 1//numero de articulacoes

//cada perna possui duas tranformacoes (usando rotacao e escala) para cada ponto de articulacao

#define LEG_1_P1_X 50//coordenada X do ponto 1 da perna 1
#define LEG_1_P1_Y 100//coordenada y do ponto 1 da perna 1
#define LEG_1_P2_X 75//coordenada X do ponto 2 da perna 1
#define LEG_1_P2_Y 120//coordenada y do ponto 2 da perna 1
#define LEG_1_ATTACH_POINT 6//posicao em que a perna 1 se liga ao cefalotorax
#define LEG_1_P1_ROTATION1 10*ROTATE_STEP_SIZE//rotacao 1 da seccao 1 da perna 1
#define LEG_1_P2_ROTATION1 20*ROTATE_STEP_SIZE//rotacao 1 da seccao 2 da perna 1
#define LEG_1_P1_ROTATION2 -10*ROTATE_STEP_SIZE//rotacao 2 da seccao 1 da perna 1
#define LEG_1_P2_ROTATION2 10*ROTATE_STEP_SIZE//rotacao 2 da seccao 2 da perna 1
#define LEG_1_P1_SCALE1 0.8//escala 1 da seccao 1 da perna 1
#define LEG_1_P2_SCALE1 1.1//escala 1 da seccao 2 da perna 1
#define LEG_1_P1_SCALE2 0.5//escala 2 da seccao 1 da perna 1
#define LEG_1_P2_SCALE2 1//escala 2 da seccao 2 da perna 1

#define LEG_2_P1_X 55//coordenada X do ponto 1 da perna 2
#define LEG_2_P1_Y 12//coordenada y do ponto 1 da perna 2
#define LEG_2_P2_X 74//coordenada X do ponto 2 da perna 2
#define LEG_2_P2_Y -40//coordenada y do ponto 2 da perna 2
#define LEG_2_ATTACH_POINT 2//posicao em que a perna 2 se liga ao cefalotorax
#define LEG_2_P1_ROTATION1 -20*ROTATE_STEP_SIZE//rotacao 1 da seccao 1 da perna 2
#define LEG_2_P2_ROTATION1 25*ROTATE_STEP_SIZE//rotacao 1 da seccao 2 da perna 2
#define LEG_2_P1_ROTATION2 20*ROTATE_STEP_SIZE//rotacao 2 da seccao 1 da perna 2
#define LEG_2_P2_ROTATION2 10*ROTATE_STEP_SIZE//rotacao 2 da seccao 2 da perna 2
#define LEG_2_P1_SCALE1 1//escala 1 da seccao 1 da perna 2
#define LEG_2_P2_SCALE1 0.3//escala 1 da seccao 2 da perna 2
#define LEG_2_P1_SCALE2 1//escala 2 da seccao 1 da perna 2
#define LEG_2_P2_SCALE2 0.4//escala 2 da seccao 2 da perna 2

#define LEG_3_P1_X 52//coordenada X do ponto 1 da perna 3
#define LEG_3_P1_Y 5//coordenada y do ponto 1 da perna 3
#define LEG_3_P2_X 71//coordenada X do ponto 2 da perna 3
#define LEG_3_P2_Y -47//coordenada y do ponto 2 da perna 3
#define LEG_3_ATTACH_POINT 89//posicao em que a perna 3 se liga ao cefalotorax
#define LEG_3_P1_ROTATION1 -20*ROTATE_STEP_SIZE//rotacao 1 da seccao 1 da perna 3
#define LEG_3_P2_ROTATION1 35*ROTATE_STEP_SIZE//rotacao 1 da seccao 2 da perna 3
#define LEG_3_P1_ROTATION2 -30*ROTATE_STEP_SIZE//rotacao 2 da seccao 1 da perna 3
#define LEG_3_P2_ROTATION2 20*ROTATE_STEP_SIZE//rotacao 2 da seccao 2 da perna 3
#define LEG_3_P1_SCALE1 1//escala 1 da seccao 1 da perna 3
#define LEG_3_P2_SCALE1 0.5//escala 1 da seccao 2 da perna 3
#define LEG_3_P1_SCALE2 1//escala 2 da seccao 1 da perna 3
#define LEG_3_P2_SCALE2 0.6//escala 2 da seccao 2 da perna 3

#define LEG_4_P1_X 49//coordenada X do ponto 1 da perna 4
#define LEG_4_P1_Y -2//coordenada y do ponto 1 da perna 4
#define LEG_4_P2_X 95//coordenada X do ponto 2 da perna 4
#define LEG_4_P2_Y -130//coordenada y do ponto 2 da perna 4
#define LEG_4_ATTACH_POINT 86//posicao em que a perna 4 se liga ao cefalotorax
#define LEG_4_P1_ROTATION1 -45*ROTATE_STEP_SIZE//rotacao 1 da seccao 1 da perna 4
#define LEG_4_P2_ROTATION1 30*ROTATE_STEP_SIZE//rotacao 1 da seccao 2 da perna 4
#define LEG_4_P1_ROTATION2 -20*ROTATE_STEP_SIZE//rotacao 2 da seccao 1 da perna 4
#define LEG_4_P2_ROTATION2 8*ROTATE_STEP_SIZE//rotacao 2 da seccao 2 da perna 4
#define LEG_4_P1_SCALE1 1//escala 1 da seccao 1 da perna 4
#define LEG_4_P2_SCALE1 0.75//escala 1 da seccao 2 da perna 4
#define LEG_4_P1_SCALE2 1//escala 2 da seccao 1 da perna 4
#define LEG_4_P2_SCALE2 0.5//escala 2 da seccao 2 da perna 4

#define LEG_5_P1_X -50//coordenada X do ponto 1 da perna 5
#define LEG_5_P1_Y 100//coordenada y do ponto 1 da perna 5
#define LEG_5_P2_X -75//coordenada X do ponto 2 da perna 5
#define LEG_5_P2_Y 120//coordenada y do ponto 2 da perna 5
#define LEG_5_ATTACH_POINT 39//posicao em que a perna 5 se liga ao cefalotorax
#define LEG_5_P1_ROTATION1 10*ROTATE_STEP_SIZE//rotacao 1 da seccao 1 da perna 5
#define LEG_5_P2_ROTATION1 -10*ROTATE_STEP_SIZE//rotacao 1 da seccao 2 da perna 5
#define LEG_5_P1_ROTATION2 -10*ROTATE_STEP_SIZE//rotacao 2 da seccao 1 da perna 5
#define LEG_5_P2_ROTATION2 -20*ROTATE_STEP_SIZE//rotacao 2 da seccao 2 da perna 5
#define LEG_5_P1_SCALE1 0.5//escala 1 da seccao 1 da perna 5
#define LEG_5_P2_SCALE1 1//escala 1 da seccao 2 da perna 5
#define LEG_5_P1_SCALE2 0.8//escala 2 da seccao 1 da perna 5
#define LEG_5_P2_SCALE2 1.1//escala 2 da seccao 2 da perna 5

#define LEG_6_P1_X -55//coordenada X do ponto 1 da perna 6
#define LEG_6_P1_Y 12//coordenada y do ponto 1 da perna 6
#define LEG_6_P2_X -74//coordenada X do ponto 2 da perna 6
#define LEG_6_P2_Y -40//coordenada y do ponto 2 da perna 6
#define LEG_6_ATTACH_POINT 43//posicao em que a perna 6 se liga ao cefalotorax
#define LEG_6_P1_ROTATION1 -20*ROTATE_STEP_SIZE//rotacao 1 da seccao 1 da perna 6
#define LEG_6_P2_ROTATION1 -10*ROTATE_STEP_SIZE//rotacao 1 da seccao 2 da perna 6
#define LEG_6_P1_ROTATION2 20*ROTATE_STEP_SIZE//rotacao 2 da seccao 1 da perna 6
#define LEG_6_P2_ROTATION2 -25*ROTATE_STEP_SIZE//rotacao 2 da seccao 2 da perna 6
#define LEG_6_P1_SCALE1 1//escala 1 da seccao 1 da perna 6
#define LEG_6_P2_SCALE1 0.4//escala 1 da seccao 2 da perna 6
#define LEG_6_P1_SCALE2 1//escala 2 da seccao 1 da perna 6
#define LEG_6_P2_SCALE2 0.3//escala 2 da seccao 2 da perna 6

#define LEG_7_P1_X -52//coordenada X do ponto 1 da perna 7
#define LEG_7_P1_Y 5//coordenada y do ponto 1 da perna 7
#define LEG_7_P2_X -71//coordenada X do ponto 2 da perna 7
#define LEG_7_P2_Y -47//coordenada y do ponto 2 da perna 7
#define LEG_7_ATTACH_POINT 46//posicao em que a perna 7 se liga ao cefalotorax
#define LEG_7_P1_ROTATION1 30*ROTATE_STEP_SIZE//rotacao 1 da seccao 1 da perna 7
#define LEG_7_P2_ROTATION1 -20*ROTATE_STEP_SIZE//rotacao 1 da seccao 2 da perna 7
#define LEG_7_P1_ROTATION2 20*ROTATE_STEP_SIZE//rotacao 2 da seccao 1 da perna 7
#define LEG_7_P2_ROTATION2 -35*ROTATE_STEP_SIZE//rotacao 2 da seccao 2 da perna 7
#define LEG_7_P1_SCALE1 1//escala 1 da seccao 1 da perna 7
#define LEG_7_P2_SCALE1 0.6//escala 1 da seccao 2 da perna 7
#define LEG_7_P1_SCALE2 1//escala 2 da seccao 1 da perna 7
#define LEG_7_P2_SCALE2 0.5//escala 2 da seccao 2 da perna 7

#define LEG_8_P1_X -49//coordenada X do ponto 1 da perna 8
#define LEG_8_P1_Y -2//coordenada y do ponto 1 da perna 8
#define LEG_8_P2_X -95//coordenada X do ponto 2 da perna 8
#define LEG_8_P2_Y -130//coordenada y do ponto 2 da perna 8
#define LEG_8_ATTACH_POINT 49//posicao em que a perna 8 se liga ao cefalotorax
#define LEG_8_P1_ROTATION1 20*ROTATE_STEP_SIZE//rotacao 1 da seccao 1 da perna 8
#define LEG_8_P2_ROTATION1 -8*ROTATE_STEP_SIZE//rotacao 1 da seccao 2 da perna 8
#define LEG_8_P1_ROTATION2 45*ROTATE_STEP_SIZE//rotacao 2 da seccao 1 da perna 8
#define LEG_8_P2_ROTATION2 -30*ROTATE_STEP_SIZE//rotacao 2 da seccao 2 da perna 8
#define LEG_8_P1_SCALE1 1//escala 1 da seccao 1 da perna 8
#define LEG_8_P2_SCALE1 0.5//escala 1 da seccao 2 da perna 8
#define LEG_8_P1_SCALE2 1//escala 2 da seccao 1 da perna 8
#define LEG_8_P2_SCALE2 0.75//escala 2 da seccao 2 da perna 8

#endif