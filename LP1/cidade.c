#include <stdio.h>
void main ()
{
	char S[3];
	gets(S);
	S[2]='\0';
	if (S=="AC")
		printf("Acre - Rio Branco");
	else if (S=="AL")
		printf("Alagoas - Maceio");
	else if (S=="AP")
		printf("Amapa - Macapa");
	else if (S=="AM")
		printf("Amazonas - Manaus");
	else if (S=="BA")
		printf("Bahia - Salvador");
	else if (S=="CE")
		printf("Ceará - Fortaleza");
	else if (S=="AC")
		printf("Destrito Federal - Brasilia");
	else if (S=="ES")
		printf("Espirito Santo - Vitoria");
	else if (S=="GO")
		printf("Goias - Goiania");
	else if (S=="MA")
		printf("Maranhao - Sao Luiz");
	else if (S=="MT")
		printf("Mato Grosso - Cuiaba");
	else if (S=="MS")
		printf("Mato Grosso do Sul - Campo Grande");
	else if (S=="MG")
		printf("Minas Gerais - Belo Horizonte");
	else if (S=="PA")
		printf("Para - Belem");
	else if (S=="PB")
		printf("Paraiba - Joao Pessoa");
	else if (S=="PR")
		printf("Pernambuco - Recife");
	else if (S=="PI")
		printf("Piaui - Terezina");
	else if (S=="RJ")
		printf("Rio de Janeiro - Rio de Janeiro");
	else if (S=="RN")
		printf("Rio Grande do Norte - Natal");
	else if (S=="RS")
		printf("Rio Grande do Sul - Porto Alegre");
	else if (S=="RO")
		printf("Rondonia - Porto Velho");
	else if (S=="RR")
		printf("Roraima - Boa Vista");
	else if (S=="SC")
		printf("Santa Catarina - Florianopolis");
	else if (S=="SP")
		printf("Sao Paulo - Sao Paulo");
	else if (S=="SE")
		printf("Sergipe - Aracaju");
	else if (S=="TO")
		printf("Tocantins - Palmas");
	else
		printf("ESTADO INVALIDO");
}
