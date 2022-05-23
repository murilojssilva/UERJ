%{
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
extern int yylex ();
 
#define NADA		9999
#define FRACASSO	9998
#define ACHOUDIFVAR	9997

char *msg4 = "unknow entity in source program";

typedef enum {
	Variable,
	Constant,
	Temporary,
	Function,
	Procedure
} Entity;

typedef enum {
ADD,
SUB,
MUL,
DIV,
STO,
PRINT,
J,
JF
} Operador;

/*
SymbTab: 1as 50 entradas p/ simbolos do fonte
e últimas p/ as temporarias
*/
typedef struct {
  char     asciiOfSource [20];
  Entity   entt;
  int      value;
} SymbTab;

SymbTab symbTab [100];

int	indSymb,  
	indTemp;

int	topTab=0;   // first 50 entries are programmer symbols
int	topTemp=50; // last  50 entries are temporary

int searchSymbTab (char *symb){ 
  int k;
  for (k = 0; k < topTab; k++)
    if (strcmp(symb,symbTab[k].asciiOfSource) == 0)
      return k;
  return topTab;
};

int insertSymbTab (char *symb, Entity whichEntt) {
  int existingSym, current, aux;
  
  existingSym = searchSymbTab (symb);
  if (existingSym < topTab) return existingSym;
  current = topTab;
  if ((whichEntt == Variable) || (whichEntt == Constant)) {
     strcpy(symbTab[current].asciiOfSource,symb);
     symbTab[current].entt = whichEntt;
     }
  else {
    char * ptMsg = (char *) malloc (80);
    strcpy(ptMsg,"Unknown entity type: "); 
    strcat(ptMsg,symb); 
    yyerror (ptMsg);
    };
  if (whichEntt == Constant)
     symbTab[current].value = atoi(symb);
  if (whichEntt == Variable) 
     symbTab[current].value = 0;  
  topTab++;
  return current;
};
int temp () { 
	char nomeTemporaria[4];
	int retorno;
        sprintf(nomeTemporaria,"t%d",topTemp-50);
	strcpy(symbTab[topTemp].asciiOfSource,nomeTemporaria);
	symbTab[topTemp].entt = Temporary;
        retorno=topTemp;
	topTemp++;
	return (retorno);
};
void printSymbTable () {
int i, j, inicio, fimTrecho;
printf("> Tabela de Simbolos \n");
inicio=0;
j=0;
fimTrecho = topTab-1;
while (j <= 1) {
  for (i=inicio; i <= fimTrecho; i++) { 
    switch (symbTab[i].entt) {
      case Variable: printf("> Variable: ");break;
      case Constant: printf("> Numerical Constant: ");break;
      case Temporary: printf("> Temporary: ");break;
      case Function: printf("> Function: ");break;
      case Procedure: printf("> Procedure: ");break;
      default: yyerror(msg4);break;
    };
    printf("%s ", symbTab[i].asciiOfSource);
    printf("%d \n", symbTab[i].value);
    };// do for
  j++;
  inicio = 50;
  fimTrecho=topTemp-1; 
};
};

char nomeOperador  [6] [7] = {
"ADD","SUB","MUL","DIV","STO","PRINT"};

struct Quadrupla {
	Operador        op;
	int             operando1;
	int             operando2;
	int             operando3;
	} quadrupla [ 100 ];

int prox;

void gera (Operador codop,int end1,int end2,int end3){
	quadrupla [prox].op = codop;
	quadrupla [prox].operando1 = end1;
	quadrupla [prox].operando2 = end2;
	quadrupla [prox].operando3 = end3;
	prox++;
	};

void remenda (int posQuadrupla, Operador codop, int end1, int end2, int end3 )
{
	quadrupla [posQuadrupla].op = codop;
	quadrupla [posQuadrupla].operando1 = end1;
	quadrupla [posQuadrupla].operando2 = end2;
	quadrupla [posQuadrupla].operando3 = end3;
};

void imprimeQuadrupla(){
  int r;

  printf("> Tabela de Quadruplas \n");
  for(r=0;r<prox;r++) 
    printf("> %s %d %d %d\n",
              nomeOperador[quadrupla[r].op],                
                 quadrupla[r].operando1,
                    quadrupla[r].operando2,
                       quadrupla[r].operando3);

}; //da funcao imprimeQuadrupla

void finaliza () {
  char resposta [5];
  printSymbTable ();
  imprimeQuadrupla ();
  printf("\n End normal compilation!");
  printf("Para encerrar digite qualquer letra: \n");
  scanf("%s", resposta);
  printf("/n encerrado por sua vontade");
  exit(0);
  };

void yyerror(const char *str)
{
  printf("error: %s\n",str);
  exit (1);
};

int yywrap()
{
  return 1;
};

int main()
{
  printf("\n \n>G6 \n>"); 
  yyparse();
  return 0;
}

%}
%union{
  struct T{
    char symbol[21]; 
    int intval;}t;
 }
%token _ATRIB _EOF _ABREPAR _FECHAPAR _PTVIRG
%token _MAIS _MENOS _MULT _DIVID _PRINT
%token _ERRO
%token _N _V
%token _VIRG _INICIO _FIM _SE _SENAO _DO _ENQUANTO _INTEIRO
%type<t> Stm A B C D E F I M O T S W _N _V //Revisar: Só entram os não terminais que geram variáveis
%%
/* 
regras da gramatica e acoes semanticas
*/

/*p
S    : Stm _PTVIRG S 
     |  {finaliza ();}  		 
     ;
Stm  : _V _ATRIB E {
                   $1.intval = insertSymbTab($1.symbol, Variable);
		   gera(STO,$3.intval,$1.intval,NADA);
		   printf("\n");
		   }
     | _PRINT _ABREPAR E _FECHAPAR {
                   gera(PRINT,$3.intval, NADA, NADA);
		   //printf("\n");}
		   printf("%d\n", $3.intval); printf("> ");}
     ;
E    : E _MAIS T {
                 $$.intval = temp(); 
		gera (ADD,$1.intval,$3.intval,$$.intval);
      }
     | E _MENOS T{    
                 $$.intval = temp(); 
		 gera (SUB,$1.intval,$3.intval,$$.intval);}
     | T	 {	
                 $$.intval = $1.intval;}
T    : T _MULT F {	
                 $$.intval = temp(); 
		 gera (MUL,$1.intval,$3.intval,$$.intval);}	
     |T _DIVID F {	
                 $$.intval = temp(); 
		 gera (DIV,$1.intval,$3.intval,$$.intval);}
      | F	 {	
                 $$.intval = $1.intval;}
F     : _ABREPAR E _FECHAPAR 
                 {
		 $$.intval = $2.intval;} 
F    : _V {$$.intval=insertSymbTab($1.symbol, Variable);
          }

     | _N {$$.intval=insertSymbTab($1.symbol, Constant);
          } 
     ;
*/


P	:	Stm _PTVIRG P | {
			finaliza ();
		};
Stm	:	D C
       /* empty */ {finaliza ();};
D	:	L _PTVIRG D 
	  |	L _PTVIRG;

L	:	T _V {
			
		}
	  |	L _VIRG _V {
		}
T	:	_INTEIRO {
			{intVar = INT_VAR;};
		}
C	:	_INICIO B _FIM {
			$$.intval = temp();
			$$.intval = $2.intval;
		}
B	:	S _PTVIRG B 
	  |	S {
			$$.intval = $1.intval;
		}
S	:	A {
			$$.intval = $1.intval;
		}
	  |	I {
			$$.intval = $1.intval;
		}
	  |	W {
			$$.intval = $1.intval;
		}
	  |	O {
			$$.intval = $1.intval;
		}
A	:	_N _ATRIB E {
		  $1.intval = insertSymbTab($1.symbol, Variable); 
      gera(STO,$3.intval,$1.intval,NADA);
		}
I   : _IF E M C {
      remenda($3.intval , JF, $2.intval , prox, NADA); 
    };
    | _SE E M C M _SENAO C {
      	remenda($3.intval, JF, $2.intval, $5.intval + 1, NADA);
    }
W   : _DO C _ENQUANTO E {
      gera(JF, $2.intval, NADA, NADA);
    }
O   : _PRINT _ABREPAR E _FECHAPAR { //OK
      gera(PRINT,$3.intval, NADA, NADA);
		  printf("%d\n", $3.intval); printf("> ");
    }
E   : E _MAIS T { //OK
      $$.intval = temp(); 
		  gera (ADD,$1.intval,$3.intval,$$.intval);
    }
    | E _MENOS T { //OK
      $$.intval = temp(); 
		  gera (SUB,$1.intval,$3.intval,$$.intval);
    }
    | T { //OK
      $$.intval = $1.intval;
    }
T   : T _MULT F { //OK
      $$.intval = temp(); 
		  gera(MUL,$1.intval,$3.intval,$$.intval);
    }
    | T _DIVID F { //OK
      $$.intval = temp(); 
		  gera (DIV,$1.intval,$3.intval,$$.intval);
    }
    | F { //OK
      $$.intval = $1.intval;
    }
F   : _ABREPAR E _FECHAPAR { //OK
      $$.intval = $2.intval;
    }
    | _V { //OK
      $$.intval=insertSymbTab($1.symbol, Variable);
    }
    | _N { //OK
      $$.intval=insertSymbTab($1.symbol, Constant);
    }
M   : {
      $$.intval = prox;
      prox++;
    }
%%

void atendeReclamacao () {
  int aux;
  aux = 0; // trying avoid compilation error in bison
  }
