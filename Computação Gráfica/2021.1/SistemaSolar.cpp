#include<SistemaSolar.h>

GLfloat	 lightPos2[] = { 0.0f, 0.0f, 0.0f, 1.0f };
SistemaSolar::SistemaSolar() {
}
void SistemaSolar::adicionaPlaneta(Planeta planeta) {
	p.push_back(planeta);
}
void SistemaSolar::desenha(double tempo) {
	int c = 0;
	for (Planeta pla : p) {
		pla.desenha(tempo);
		if (c++ == 0)glLightfv(GL_LIGHT0, GL_POSITION, lightPos2);
	}
}