struct professor *criaProfessor(char nome[],int matricula);
void insereProfessor(char nome[],int matricula, struct professor ** p);
void excluiProfessor(char nome[], int matricula, struct professor ** p);
void liberar(struct professor *exc);
struct professor *alteraProfessor(char nome[], int matricula, struct professor * p);
struct professor *buscarProfessor(char nome[], int matricula, struct professor * p);
struct professor *listarProfessor(struct professor *p);

struct aluno *criarAluno(char nome[],int matricula);
void inserirAluno(char nome[],int matricula, struct aluno ** a);
void excluiAluno(char nome[], int matricula, struct aluno ** a);
void libera(struct aluno * aux);
struct aluno *alteraAluno(char nome[], int matricula, struct aluno * a);
struct aluno *buscaAluno(char nome[], int matricula, struct aluno *a);
struct aluno *listarAluno(struct aluno *a);

struct turma *criaTurma(char nome[],int professor,int vagas,struct professor *p);
void insereTurma(char nome[],int professor, int vagas,struct turma ** t,struct professor *p);
void libere(struct turma *del);
void excluiTurma(char nome[], int matricula,int vagas,int qtdInscritos, struct turma ** t,struct professor *p);
struct turma *alteraTurma(char nome[],int matricula,int vagas,int qtdInscritos,int professor, struct turma * t,struct professor *p);
struct turma *buscarTurma(char nome[], int matricula, struct professor * p,struct turma *t);
void inserirAlunoTurma(char nome[],int matricula, struct turma *t,struct aluno *a);
void buscarAlunoTurma(int matricula, struct turma *t, struct aluno **a);
struct turma *listarTurmas(struct turma *t);

char MenuPrincipal(char MPrin);
char MenuTurmas(char MTurm);
char MenuAlunos(char MTurm);
char MenuProfessores(char MTurm);
