#include<Asteroids.h>
#include<iostream>
Asteroids::Asteroids(float dist_min, float dist_max, float tam_min, float tam_max, int count, double incl) {
	std::cout << "Gerando asteroids" << std::endl;
	srand(time(NULL));
	int r = rand();
	double dist, trans, tam;
	bool inseriu;
	int j;
	Asteroids *temp;
	for (int i = 0; i < count; i++) {
		inseriu = false;
		j = 0;
		temp = &Asteroids(0, 0, 0, incl);
		while (!inseriu && j<1000)
		{
			dist = ((double)rand() / (RAND_MAX + 1)) * (dist_max - dist_min + 1) + dist_min;
			trans = ((double)rand() / (RAND_MAX + 1)) * (360 - 0 + 1) + 0;
			tam = ((double)rand() / (RAND_MAX + 1)) * (tam_max - tam_min + 1) + tam_min;
			temp->reset(dist, trans, tam, incl);
			if (testa(*temp)) {
				a.push_back(*temp);
				inseriu = true;
			}
			j++;
		}
	}
	std::cout << "Terminou de gerar asteroids" << std::endl;
}
Asteroids::Asteroids(double distancia, double translacao, double tamanho, double incl) {
	reset(distancia, translacao, tamanho,incl);
}
void Asteroids::reset(double distancia, double translacao, double tamanho,double incl){
	distancia = distancia*dScale;
	r = tamanho *tScale;
	double incliOrbital = ((double)rand() / (RAND_MAX + 1));

	x = sin(translacao)*distancia;
	y = cos(translacao)*distancia;
	z = incliOrbital*incl;
}
void Asteroids::desenha() {
	int t = 0;
	glPushMatrix();
	glColor3f(.7, .7, .7);
	for (Asteroids s : a) {
		glPushMatrix();
		glTranslatef(s.x, s.y, s.z);
		glutSolidSphere(s.r, 5, 5);
		glPopMatrix();
	}
	glColor3f(1, 1, 1);
	glPopMatrix();
}

bool Asteroids::testa(Asteroids t) {
	/*for (Asteroids s : a) {
		if (dist(s, t) < s.r + t.r)return false;
	}*/
	return true;
}

double Asteroids::dist(Asteroids a, Asteroids b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
}