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

typedef struct {
  char     asciiOfSource [20];
  Entity   entt;
  int      value;
} SymbTab;

SymbTab symbTab [100];

int	indSymb,  
	indTemp, intVar;

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
fimTrecho = topTab-1;// trecho dos s�mbolos do programa  
while (j <= 1) {
  for (i=inicio; i <= fimTrecho; i++) { 
    switch (symbTab[i].entt) {
      case Variable: {printf("> Type Entity: Variable           - Address: %d - ",i);break;};
      case Constant: {printf("> Type Entity: Numerical Constant - Address: %d - ",i);break;};
      case Temporary:{printf("> Type Entity: Temporay           - Address: %d - ",i);break;};
      case Function: {printf("> Type Entity: Function           - Address: %d - ",i);break;};
      case Procedure:{printf("> Type Entity: Procedure          - Address: %d - ",i);break;};
      default: {yyerror(msg4);break;};
    }; //do switch
    if (symbTab[i].entt == Constant)
      printf("Number of Constant: %s - ", symbTab[i].asciiOfSource);
    else
      printf("Name of Entity    : %s - ", symbTab[i].asciiOfSource);
    if((symbTab[i].entt == Variable) || 
       (symbTab[i].entt == Temporary)||
       (symbTab[i].entt == Constant))
       printf("Value of Entity: % \n", symbTab[i].value);
    else 
      printf("\n");
  };// do for
  j++;
  inicio = 50;
  fimTrecho=topTemp-1;  // trecho das tempor�rias
}; // do while
}; // da function printSymbTable

typedef enum {
ADD,
SUB,
MUL,
DIV,
STO,
PRINT, 
JF
} Operador;
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
void imprimeQuadrupla(){
  int r;
  printf("> Tabela de Quadruplas \n");
  for(r=0;r<prox;r++){
    if (quadrupla[r].operando2 == NADA) 
      printf("> Instruction Address: %d - %s, %d \n",
        r,nomeOperador[quadrupla[r].op],quadrupla[r].operando1);
    if ((quadrupla[r].operando2 != NADA)&&(quadrupla[r].operando3 == NADA))
      printf("> Instruction Address: %d - %s, %d, %d \n",
                r,nomeOperador[quadrupla[r].op],quadrupla[r].operando1,quadrupla[r].operando2);
    if ((quadrupla[r].operando2 != NADA)&&(quadrupla[r].operando3 != NADA))
	printf("> Instruction Address: %d - %s, %d, %d, %d\n",
                r,nomeOperador[quadrupla[r].op],quadrupla[r].operando1,quadrupla[r].operando2,quadrupla[r].operando3);
  } // do for
}; //da funcao imprimeQuadrupla

void finaliza () {
  char resposta [5];
  printSymbTable ();
  imprimeQuadrupla ();
  printf("\n End normal compilation!");
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
%union{ /***********************?*********/
  struct T{
    char symbol[21]; 
    int intval;
    int indiceQuadrupla }t;
 }
%token _ATRIB _EOF _ABREPAR _FECHAPAR _PTVIRG _VIR _RET
%token _MAIS _MENOS _MULT _DIVID _PRINT _INT 
%token _BEGIN _IF _ELSE _DO _WHILE _END
%token _ERRO 
%token _N _V
%type<t> A B C D E F I M O T S W N _N _V 
%%

P   : D C 
      /* empty */ {finaliza ();};

D   : L _PTVIRG D
    | L _PTVIRG;

L   : T _V /*FALTANDO COMPLETAR A GRAMATICA*/ {
      }
    | L _VIR _V {
      };

T   : _INT {intVar = INT_VAR;};

C   : _BEGIN B _END 
    {
      $$.intval = temp();
      $$.intval = $2.intval;
    };

B   : S _PTVIRG B 
    | S {
      $$.intval = $1.intval;
    };

S   : A {$$.intval = $1.intval;}
    | I {$$.intval = $1.intval;}
    | W {$$.intval = $1.intval;}
    | O {$$.intval = $1.intval;};

A   : _V _ATRIB E {
      $$.intval = insertSymbTab($3.symbol, Variable); 
      gera(STO,$3.intval,$1.intval,NADA);
    };

I   : _IF E M C {
      remenda($3.intval , JF, $2.intval , prox, NADA); 
    };

W   : _DO N C _WHILE E {
      gera(JF, $2.intval, NADA, NADA);
    };        /** W -> do C while E */

O   : _PRINT _ABREPAR E _FECHAPAR  {
      gera(PRINT, $3.intval, NADA, NADA);
    };        /**  O -> print (E) */

E   : E _MAIS T {
        $$.intval = temp();
        gera(ADD, $1.intval, $3.intval, $$.intval);
      }
    | E _MENOS T {
        $$.intval = temp();
        gera(SUB, $1.intval, $3.intval, $$.intval);
      }
    | T {
      $$.intval = $1.intval;
    };        /**E -> E + T | E – T | T*/

T   : T _MULT F {
        $$.intval = temp();
        gera(MUL, $1.intval, $3.intval, $$.intval);
      } 
    | T _DIVID F {
        $$.intval = temp();
        gera(DIV, $1.intval, $3.intval, $$.intval);
    } 
    | F { 
      $$.intval = $1.intval; 
    };        /** T -> T * F | T / F | F */

F   : _ABREPAR E _FECHAPAR   {
      $$.intval = $2.intval;
    }
    | _V {
      $$.intval =  insertSymbTab($1.symbol, Variable);
    }
    | _N {
      $$.intval = insertSymbTab($1.symbol, Constant);
    };        /** F -> ( E ) | id | n */

M   : { 
    $$.intval = prox;
    prox++;
    };

N : {$$.intval = prox;};


%%

void atendeReclamacao () {
  int aux;
  aux = 0; // trying avoid compilation error in bison
  }