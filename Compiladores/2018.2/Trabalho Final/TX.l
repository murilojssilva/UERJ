%{
#include "y.tab.h"
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
INT             "int"
BEGIN           "begin"
END             "end"
IF              "if"
ELSE            "else"
DO              "do"
WHILE           "while"
PRINT           "print"
IDENT		{ALFA}({ALFA}|{DIGIT})*
WS              [ \t]*
ATRIB		"="
LP              "("
RP              ")"
PTV             ";"
RET             [\n]
VIR             ","

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
{VIR}           {
                return _VIRG;
                }
{INT}           {
                return _INT;
                }
{PRINT}         {
		return _PRINT;
		}
{BEGIN}         {
                return _BEGIN;
                }
{IF}            {
                return _IF;
                }
{ELSE}          {
                return _ELSE;
                }
{DO}            {
                return _DO;
                }
{WHILE}            {
                return _WHILE;
                }
{END}           {
                return _END;
                }
{NUMBER}        {
		strcpy(yylval.t.symbol, yytext);
                return _N;
                }
{IDENT}         {
		strcpy(yylval.t.symbol, yytext);
		return _V;
		}
{RET}           {
                return yytext[0];
                }
