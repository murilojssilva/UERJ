/*6. Escrever uma programa em que leia dois valores para as variáveis A e B, e
efetuar as trocas dos valores de forma que a variável A passe a possuir o valor
da variável B e a variável B passe a possuir o valor da variável A. Apresentar
os valores trocados.
Lembrando que temos que ter 3 variáveis para que uma haja como variável
de armazenamento, ou seja, para evitar que o valor original de a se perca é
necessário associar a uma outra variável (denominada usualmente de
variável auxiliar) tal valor, estabelecer uma associação de a com o valor em b
e, por último, associar b ao valor "salvo" na variável auxiliar.*/

import java.util.Scanner;

public class Ex06 {

	public static void main(String[] args){

		int a, b, aux;

		Scanner sc = new Scanner(System.in);

		System.out.println("Digite o valor de A: ");
		a = sc.nextInt();

		System.out.println("Digite o valor de B: ");
		b = sc.nextInt();

		aux = a;
		a = b;
		b = aux;

		System.out.println("O valor de A é:" +a);
		System.out.println("O valor de B é:" +b);
	}

}
