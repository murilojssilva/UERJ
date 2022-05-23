
#include<Planeta.h>
#include<vector>
using namespace std;
class SistemaSolar {
private:
	vector<Planeta> p;
public:
	SistemaSolar();
	void adicionaPlaneta(Planeta p);
	void desenha(double tempo);

};