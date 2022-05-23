#pragma once
#include<vector>
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include<Constants.h>
#include <time.h>
#include <stdlib.h>
class Asteroids{
private:
	int count;
	std::vector<Asteroids> a;
public:
	double x;
	double y;
	double r;
	double z;
	Asteroids() {}
	Asteroids(float dist_min, float dist_max, float tam_min, float tam_max, int count, double incl);
	Asteroids(double distancia, double translacao, double tamanho, double incl);
	void reset(double distancia, double translacao, double tamanho, double incl);
	void desenha();
	bool testa(Asteroids t);
	double dist(Asteroids a, Asteroids b);
};