struct professor;
struct professor *criaProfessor(char nome[],int matricula);
void insereProfessor(char nome[],int matricula, struct professor ** p);
void excluiProfessor(char nome[], int matricula, struct professor ** p);
void liberar(struct professor *exc);
struct professor *alteraProfessor(char nome[], int matricula, struct professor * p);
struct professor *buscarProfessor(char nome[], int matricula, struct professor * p);
struct professor *listarProfessor(struct professor *p);
