%{
#include "TV.tab.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *yytext;
YYSTYPE yylval;
%}

ALFA 		[A-Za-z_]
PLUS            [\+]
MINUS           [\-]
TIMES           [\*]
DIVIDE          [/]
DIGIT           [0-9]
NUMBER          ({DIGIT}+)
PRINT           "print"
IDENT		{ALFA}({ALFA}|{DIGIT})*
WS              [ \t]*
ATRIB		    "="
LP              "("
RP              ")"
VIRG            ","
INICIO          "begin"
FIM             "end"
SE              "if"
SENAO           "else"
DO              "do"
ENQUANTO        "while"
INTEIRO         "int"
PTV             ";"
RET             [\n]

%%

{WS}            {
                /* eat up white space */
                }
{PLUS}          {
                return _MAIS;
                }
{TIMES}         {
                return _MULT;
                }
{MINUS}         {
                return _MENOS;
                }
{DIVIDE}        {
                return _DIVID;
                }
{ATRIB}		{
		return _ATRIB;
		}
{LP}            {
                return _ABREPAR;
                }
{RP}            {
                return _FECHAPAR;
                }
{PTV}		{
		return _PTVIRG;
		}

{PRINT}         {
		return _PRINT;
		}
{NUMBER}        {
		strcpy(yylval.t.symbol, yytext);
                return _N;
                }
{VIRG} {
    return _VIRG;
}
{INICIO} {
    return _INICIO;
}
{FIM} {
    return _FIM;
}
{SE} {
    return _SE;
}
{SENAO} {
    return _SENAO;
}
{DO} {
    return _DO;
}
{ENQUANTO} {
    return _ENQUANTO;
}
{INTEIRO} {
    return _INTEIRO;
}
{IDENT}         {
		strcpy(yylval.t.symbol, yytext);
		return _V;
		}
{RET}           {
                return yytext[0];
                }
