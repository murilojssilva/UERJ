#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUT 0
#define SIN 1
#define SOUT 2
#define INT 3
#define FLOAT 4

void main()
{
	FILE *file,*file1;
	char nomearq[20],nomearq2[20];
	char *str = (char*) malloc(sizeof(char));
	char *num = (char*) malloc(sizeof(char));
	char c;
	float decimal = 0;
	int i = 0, x = 1, state = OUT,j = 0, y = 1, p=0, string = 0;
	gets(nomearq);
	gets(nomearq2);
	file = fopen(nomearq,"r");
	file1 = fopen(nomearq2,"w");
	while (c=fgetc(file)!=EOF) //para string
	{
		if(c == '"' && state == OUT) { //Verificando se é string.
			state = SIN;
			
		} else if(c != '"' && state == SIN) {
			str[i] = c;
			str = (char*) realloc(str, x*sizeof(char));
		} else if(c == '"' && state == SIN) {
			state = SOUT;
		} else if(c == '+' && state == SOUT) {
			state = OUT;

		} if(c == '(' && state == OUT) { //Inteiros dentro de parêntes.
			str[i] = '\0';
			printf("%s", str);
			free(str);
			str = (char*) malloc(sizeof(char));;
			i = 0; x = 1;
			state = INT;
			} else if((c >= 48 && c <= 57) && (state == INT || state == FLOAT)) {
				num[j] = (char) c;
				j++; y++;
				num = (char*) realloc(num, y*sizeof(char));
			} else if(c == '.' && (state == INT || state == FLOAT)) {
				num[j] = (char) c;
				j++; y++;
				num = (char*) realloc(num, y*sizeof(char));
				state = FLOAT;
			} else if(c == '+' && (state == INT || state == FLOAT)) {
				num[j] = '\0';
				decimal += atof(num);
				free(num);
				num = (char*) malloc(sizeof(char));
				j = 0; y = 1;
			} else if(c == ')' && (state == INT || state == FLOAT)) {
				num[j] = '\0';
				decimal += atof(num);
				free(num);
				num = (char*) malloc(sizeof(char));
				if(state == FLOAT) {
					printf("%f", decimal);
				} else if(state == INT) {
					printf("%d", (int) decimal);
				}
				decimal = 0; j = 0; y = 1;
				state = SOUT;
			putchar(str[i]);
		}
		str[i] = '\0';
		for (i = 0;i < strlen(str);i++)
			fprintf (file1,"%c",str[i]);
		free(str);
		free(num);
	}
}
