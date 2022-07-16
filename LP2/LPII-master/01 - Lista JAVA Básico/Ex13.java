/*13. Escreva um programa que entre com um número e o imprima caso seja maior
do que 20.*/

import java.util.Scanner;

public class Ex13{

	public static void main(String[] args){

		int numero;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite um número: ");
		numero = sc.nextInt();

		if (numero > 20){
			System.out.printf("O número é maior que 20, portanto, será imprimido: %d\n", numero);
		}
		else {
			System.out.printf("Seu número é menor que 20, portanto não será imprimido.\n");
		}
	}
}