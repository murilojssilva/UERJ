#pragma once
#include<vector>
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <RgbImage.h>
#include <Main.h>
#include<Constants.h>
#include<Asteroids.h>

using namespace std;
class Planeta {
private:
	double translacao, rotacao, tamanho, distancia, inclinacao,incliOrbital;
	vector<Planeta> l;
	bool texture = false;
	GLuint textureID;
	GLUquadric *quad;
	Asteroids a;
	bool aneis=false;
public:
	Planeta(double distancia, double translacao, double rotacao, double tamanho, double inclinacao, double incliOrbital) : Planeta(distancia, translacao, rotacao, tamanho, inclinacao, incliOrbital, NULL) {};
	Planeta(double distancia, double translacao, double rotacao, double tamanho, double inclinacao,double incliOrbital, char * texture);
	void adicionaLua(Planeta lua);
	void desenha(double tempo);
	double meuMod(double, float);
	void desenhaOrbita();
	void setTexture(char*);
	void setAneis(Asteroids);
};