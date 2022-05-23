#include <Planeta.h>
Planeta::Planeta(double distancia, double translacao, double rotacao, double tamanho, double inclinacao,double incliOrbital, char * texture) {

	this->translacao = translacao;
	this->rotacao = rotacao;
	this->inclinacao = inclinacao;
	this->incliOrbital = incliOrbital*(distancia<0.1 ? 0 : 5);
	this->distancia = distancia*dScale;
	this->tamanho = tamanho *tScale*(distancia<0.1 ? .05 : 1);
	if(texture!=NULL)setTexture(texture);
}


void Planeta::adicionaLua(Planeta lua) {
	l.push_back(lua);
}
 void Planeta::desenha(double tempo) {
	
	double tra, rot, incli;
	
	tra = meuMod(tempo,translacao) * 360 / translacao;
	
	
	rot = meuMod(tempo,rotacao) * 360 / rotacao;

	glPushMatrix();
	glRotatef(incliOrbital, 0, 1, 0);
	glTranslatef(sin(tra)*distancia, cos(tra)*distancia, 0);

	glRotatef(inclinacao, 0, 1, 0);
	glRotatef(rot, 0, 0, 1);
	
	if (texture) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		gluQuadricTexture(quad, 1);
		gluSphere(quad,tamanho, 50, 50);
		
		glDisable(GL_TEXTURE_2D);
	}
	else {
		glutSolidSphere(tamanho, 100, 100);
	}

	for (Planeta lua:l) lua.desenha(tempo);

	if (aneis)a.desenha();
	glPopMatrix();
	if (showOrbit()) desenhaOrbita();
}
void Planeta::desenhaOrbita() {
	glPushMatrix();
	
	glDisable(GL_LIGHTING);

	glRotatef(incliOrbital, 0, 1, 0);
	glBegin(GL_LINE_STRIP);
	
	for (float angle = 0.0f; angle < 6.283185307f; angle += 0.05f)
	{
		glVertex3f(sin(angle)*distancia, cos(angle)*distancia, 0);
	}
	glVertex3f(0.0f, distancia, 0);

	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();
}


void Planeta::setTexture(char* s) {
	texture = true;
	this->textureID = loadTexture(s);
	this->quad = gluNewQuadric();
}

double Planeta::meuMod(double a, float b) {
	return a - floor(a / b)*b;
}

void Planeta::setAneis(Asteroids a) {
	this->a = a;
	aneis = true;
}