struct aluno;
struct aluno *criarAluno(char nome[],int matricula);
void inserirAluno(char nome[],int matricula, struct aluno ** a);
void excluiAluno(char nome[], int matricula, struct aluno ** a);
void libera(struct aluno * aux);
struct aluno *alteraAluno(char nome[], int matricula, struct aluno * a);
struct aluno *buscaAluno(char nome[], int matricula, struct aluno *a);
struct aluno *listarAluno(struct aluno *a);
